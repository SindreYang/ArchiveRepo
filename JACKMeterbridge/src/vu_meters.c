#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>

#include "main.h"
#include "linedraw.h"
#include "find_image.h"

static float lp[MAX_METERS];
static SDL_Rect buf_rect[MAX_METERS];

void load_graphics_vu()
{
	meter = find_image("vu-frame-small.png");
	meter_buf = find_image("vu-frame-small.png");
}

int gfx_thread_vu(void *foo)
{
	int x1, y1, x2, y2, i;
	const float angle_scale = 15.7f;
	const float angle_offset = 0.7853975f;
	const float needle_len = 98.0f;
	const float needle_hub = 21.0f;
	const Uint32 needle = SDL_MapRGB(meter->format, 0x70, 0x70, 0x70);
	const Uint32 aa = SDL_MapRGB(meter->format, 0xC0, 0xC0, 0x60);
	float theta;

	for (i=0; i<MAX_METERS; i++) {
                lp[i] = 0.0f;
		buf_rect[i].x = dest[i].x + 30;
		buf_rect[i].y = dest[i].y + 70;
		buf_rect[i].w = 168;
		buf_rect[i].h = 86;
	}

	while (1) {
		for (i=0; i<num_meters; i++) {
			lp[i] = lp[i] * 0.8f + env[i] * bias * 0.2f;
			theta = (lp[i] * angle_scale) - angle_offset;

			if (theta < -0.7853975f) theta = -0.7853975f;
			if (theta > 0.7853975f) theta = 0.7853975f;

			x1 = 108 + (int)(sinf(theta) * needle_hub);
			y1 = 169 - (int)(cosf(theta) * needle_hub);
			x2 = 108 + (int)(sinf(theta) * needle_len);
			y2 = 169 - (int)(cosf(theta) * needle_len);

			SDL_BlitSurface(meter, buf_rect, meter_buf, buf_rect);
			draw_ptr(meter_buf, x1, y1, x2, y2, needle, aa);
			draw_ptr(meter_buf, x1, y1, x2, y2, needle, aa);
			SDL_BlitSurface(meter_buf, buf_rect, screen, buf_rect+i);
		}
		SDL_UpdateRects(screen, 1, &win);
		SDL_Delay(100);
	}

	return 0;
}
