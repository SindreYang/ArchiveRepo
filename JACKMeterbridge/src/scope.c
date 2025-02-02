#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>

#include "main.h"
#include "linedraw.h"
#include "find_image.h"
#include "envelopes.h"

static SDL_Rect buf_rect[MAX_METERS];

void load_graphics_scope()
{
	meter = find_image("scope-frame.png");
	meter_buf = find_image("scope-frame-overlay.png");
}

int gfx_thread_scope(void *foo)
{
	unsigned int i;
	const Uint32 trace = SDL_MapRGB(meter->format, 0x70, 0xFF, 0x70);

	for (i=0; i<num_scopes; i++) {
		buf_rect[i].x = dest[i].x + 24;
		buf_rect[i].y = dest[i].y + 22;
		buf_rect[i].w = 236;
		buf_rect[i].h = 236;
	}

	while (1) {
		for (i=0; i<num_scopes; i++) {
			int x=0, y=128, ym1, base;

                        SDL_BlitSurface(meter_buf, buf_rect, screen, buf_rect+i);
			for (base = 0; base < RING_BUF_SIZE - 257; base++) {
				if (ring_buf[i][base] <= 0.0f &&
						ring_buf[i][base+1] > 0.0f) {
					break;
				}
			}
			base++;
                        for (x = 0; x < 233; x++) {
				ym1 = y;
				y = (1.0f - ring_buf[i][x+base] * bias) * 118.0f;

				if (y > 235) {
					y = 235;
					continue;
				} else if (y < 1) {
					y = 1;
					continue;
				}

				if (x > 0) {
					draw_line(screen, buf_rect[i].x+x,  buf_rect[i].y+y, buf_rect[i].x+x-1, buf_rect[i].y+ym1, trace);
				}
                        }
		}
		SDL_UpdateRects(screen, 1, &win);
		SDL_Delay(50);
	}

	return 0;
}
