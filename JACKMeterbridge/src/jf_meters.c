#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>

#include "main.h"
#include "linedraw.h"
#include "find_image.h"
#include "envelopes.h"

#define TINY 1.0e-23

static float lp[MAX_METERS];
static float tau_lp[MAX_METERS/2];
static SDL_Rect buf_rect[MAX_METERS];

float tau(float *x, float *y, unsigned int n);

float tau(float *x, float *y, unsigned int n)
{
       	unsigned int n2=0,n1=0,i,j;
	long is=0;
	float aa, a2, a1;

	for (i=0; i<n; i++) {
		for (j=i; j<n; j++) {
			a1 = x[i] - x[j];
			a2 = y[i] - y[j];
			aa = a1*a2;
			if (aa) {
				++n1;
				++n2;
				aa > 0.0 ? ++is : --is;
			} else {
				if (a1) ++n1;
				if (a2) ++n2;
			}
		}
	}
	return is / (sqrtf((float)n1 * (float)n2) + TINY);
}

void load_graphics_jf()
{
	meter = find_image("jf-frame.png");
	meter_buf = find_image("jf-frame-overlay.png");
}

int gfx_thread_jf(void *foo)
{
	unsigned int i, j;
	const Uint32 trace = SDL_MapRGB(meter->format, 0x70, 0xFF, 0x70);
	const Uint32 met_red = SDL_MapRGB(meter->format, 0x30, 0x30, 0xFF);
	const Uint32 met_green = SDL_MapRGB(meter->format, 0x30, 0xFF, 0x30);

	for (i=0; i<num_meters; i++) {
		lp[i] = 0.0f;
	}

	for (i=0; i<num_scopes; i++) {
		buf_rect[i].x = dest[i].x + 10;
		buf_rect[i].y = dest[i].y + 10;
		buf_rect[i].w = 200;
		buf_rect[i].h = 227;
	}

	while (1) {
		for (i=0; i<num_scopes; i++) {
			int x=0, y=0, xm1, ym1;
			SDL_Rect cor_rect;

			SDL_FillRect(meter, buf_rect, trace);
                        SDL_BlitSurface(meter_buf, buf_rect, screen, buf_rect+i);
                        for (j=0; j<RING_BUF_SIZE; j++) {
				xm1 = x;
				ym1 = y;

				/* A touch of lowpass filter to make it easier
				 * to read */
				lp[i*2] = lp[i*2] * 0.9f + ring_buf[i*2][j] *
					bias * 0.1f;
				lp[i*2+1] = lp[i*2+1] * 0.9f +
					ring_buf[i*2+1][j] * bias * 0.1f;

				x = lp[i*2+1] * 80.0f * 0.707f -
					lp[i*2] * 80.0f * 0.707f;
				if (x > 100) {
					x = 100;
					continue;
				} else if (x < -100) {
					x = -100;
					continue;
				}

				y = lp[i*2+1] * -80.0f * 0.707f +
					lp[i*2] * -80.0f * 0.707f;
				if (y > 99) {
					y = 99;
					continue;
				} else if (y < -96) {
					y = -96;
					continue;
				}

				set_rgba(screen, buf_rect[i].x+100+x, buf_rect[i].y+100+y, trace);
#if 0
				if (j > 0) {
					draw_line(screen, buf_rect[i].x+100+x,  buf_rect[i].y+100+y, buf_rect[i].x+100+xm1, buf_rect[i].y+100+ym1, trace);
				}
#endif
                        }

			/* Draw correlation meter */
			tau_lp[i] = tau_lp[i] * 0.8f + tau((float *)ring_buf[i*2], (float *)ring_buf[i*2+1], RING_BUF_SIZE) * 0.2f;
			cor_rect.y = buf_rect[i].y + 210;
			cor_rect.h = 6;
			if (tau_lp[i] > 0.0f) {
				cor_rect.x = buf_rect[i].x+100;
				cor_rect.w = tau_lp[i] * 92.0f;
				SDL_FillRect(screen, &cor_rect, met_green);
			} else {
				cor_rect.x = buf_rect[i].x+100 + tau_lp[i] * 92.0f;
				cor_rect.w = (int)(tau_lp[i] * -92.0f) + 1;
				SDL_FillRect(screen, &cor_rect, met_red);
			}
			if (cor_rect.w > 100) printf("%d\t%f\n", cor_rect.w, tau_lp[i]);
		}
		SDL_UpdateRects(screen, 1, &win);
		SDL_Delay(25);
	}

	return 0;
}
