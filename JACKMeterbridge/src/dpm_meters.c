#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>

#include "main.h"
#include "find_image.h"
#include "envelopes.h"

int peaks[MAX_METERS];
int ptime[MAX_METERS];

int iec_scale(float db);

void load_graphics_dpm()
{
	unsigned int i;

	meter = find_image("iec268-scale.png");
	meter_buf = find_image("iec268-scale.png");

	for (i=0; i<MAX_METERS; i++) {
		peaks[i] = 0;
		ptime[i] = 0;
	}
}

int iec_scale(float db) {
         float def = 0.0f; /* Meter deflection %age */
 
         if (db < -70.0f) {
                 def = 0.0f;
         } else if (db < -60.0f) {
                 def = (db + 70.0f) * 0.25f;
         } else if (db < -50.0f) {
                 def = (db + 60.0f) * 0.5f + 5.0f;
         } else if (db < -40.0f) {
                 def = (db + 50.0f) * 0.75f + 7.5;
         } else if (db < -30.0f) {
                 def = (db + 40.0f) * 1.5f + 15.0f;
         } else if (db < -20.0f) {
                 def = (db + 30.0f) * 2.0f + 30.0f;
         } else if (db < 0.0f) {
                 def = (db + 20.0f) * 2.5f + 50.0f;
         } else {
                 def = 100.0f;
         }
 
         return (int)(def * 2.0f);
}

int gfx_thread_dpm(void *foo)
{
	unsigned int i;
	int height;
	SDL_Rect r;
	Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
	Uint32 red = SDL_MapRGB(screen->format, 240, 0, 20);
	Uint32 yellow = SDL_MapRGB(screen->format, 220, 220, 20);

	while (1) {
		for (i=0; i<num_meters; i++) {
			const float peak = env_read(i);
			height = iec_scale(20.0f * log10f(peak * bias));
			r.x = dest[i].x + 7;
			r.y = dest[i].y + 5;
			r.w = 9;
			r.h = 200 - height;
			SDL_FillRect(screen, &r, black);

			r.h = height;
			r.y = dest[i].y + 205 - height;
			SDL_FillRect(screen, &r, red);

			if (height > peaks[i]) {
				peaks[i] = height;
				ptime[i] = 0;
			} else if (ptime[i]++ > 20) {
				peaks[i] = height;
			}
			r.y = dest[i].y + 204 - peaks[i];
			if (r.y < 5) {
				r.y = 5;
			}
			r.h = 1;
			SDL_FillRect(screen, &r, yellow);
		}
		SDL_UpdateRects(screen, 1, &win);
		SDL_Delay(80);
	}

	return 0;
}
