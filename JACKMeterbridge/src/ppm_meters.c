#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>

#include "main.h"
#include "linedraw.h"
#include "find_image.h"
#include "envelopes.h"

static float lp[MAX_METERS];
static SDL_Rect buf_rect[MAX_METERS];

void load_graphics_ppm()
{
	meter = find_image("ppm-frame-small.png");
	meter_buf = find_image("ppm-frame-small.png");
}

int gfx_thread_ppm(void *foo)
{
	int x1, y1, x2, y2, i;
	const float needle_len = 82.0f;
	const float needle_hub = 16.0f;
	const float pi_4 = 0.785398f;
	const Uint32 needle = SDL_MapRGB(meter->format, 0xD0, 0xD0, 0xD0);
	const Uint32 aa = SDL_MapRGB(meter->format, 0x78, 0x78, 0x78);
	float theta;

	for (i=0; i<MAX_METERS; i++) {
		lp[i] = 0.0f;
		buf_rect[i].x = dest[i].x + 23;
		buf_rect[i].y = dest[i].y + 55;
		buf_rect[i].w = 127;
		buf_rect[i].h = 84;
	}

	while (1) {
		for (i=0; i<num_meters; i++) {
			const float peak = env_read(i);
			lp[i] = lp[i] * 0.7f + peak * bias * 0.3f;
			theta = 1.09083f * log10f(lp[i]);

			if (theta < -pi_4) theta = -pi_4;
			if (theta > pi_4) theta = pi_4;
			x1 = 89 + (int)(sinf(theta) * needle_hub);
			y1 = 138 - (int)(cosf(theta) * needle_hub);
			x2 = 89 + (int)(sinf(theta) * needle_len);
			y2 = 138 - (int)(cosf(theta) * needle_len);

			SDL_BlitSurface(meter, buf_rect, meter_buf, buf_rect);
			draw_ptr(meter_buf, x1, y1, x2, y2, needle, aa);
			SDL_BlitSurface(meter_buf, buf_rect, screen, buf_rect+i);
		}
		SDL_UpdateRects(screen, 1, &win);
		SDL_Delay(100);
	}

	return 0;
}
