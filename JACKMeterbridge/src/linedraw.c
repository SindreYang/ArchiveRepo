#include <stdlib.h>
#include <SDL.h>

/* set a pixel on an SDL_Surface, assumes that the surface is 32bit RGBA,
 * ordered ABGR (I think), probably wont work on bigendian systems */

void set_rgba(SDL_Surface *surface, Uint32 x, Uint32 y, Uint32 col)
{
	Uint32 *bufp = (Uint32 *)surface->pixels + y*surface->pitch/4 + x;
	*bufp = col;
}

/* use Bresenham's alg. to draw a line between two integer coordinates */

void draw_line(SDL_Surface *surface, int x1, int y1, int x2, int y2, const Uint32 line_col)
{
	int deltax = abs(x2 - x1);
	int deltay = abs(y2 - y1);
	int x = x1;
	int y = y1;
	int xinc1, xinc2;
	int yinc1, yinc2;
	int den, num;
	int numadd, numpixels, curpixel;

	if (x2 >= x1) {
		xinc1 = 1;
		xinc2 = 1;
	} else {
		xinc1 = -1;
		xinc2 = -1;
	}

	if (y2 >= y1) {
		yinc1 = 1;
		yinc2 = 1;
	} else {
		yinc1 = -1;
		yinc2 = -1;
	}

	if (deltax >= deltay) {
		xinc1 = 0;
		yinc2 = 0;
		den = deltax;
		num = deltax / 2;
		numadd = deltay;
		numpixels = deltax;
	} else {
		xinc2 = 0;
		yinc1 = 0;
		den = deltay;
		num = deltay / 2;
		numadd = deltax;
		numpixels = deltay;
	}

	if (SDL_MUSTLOCK(surface)) {
		if (SDL_LockSurface(surface) < 0) {
			return;
		}
	}
	for (curpixel = 0; curpixel <= numpixels; curpixel++) {
		set_rgba(surface, x, y, line_col);
		num += numadd;
		if (num >= den) {
			num -= den;
			x += xinc1;
			y += yinc1;
		}
		x += xinc2;
		y += yinc2;
	}
	if (SDL_MUSTLOCK(surface)) {
		SDL_UnlockSurface(surface);
	}
}

/* use Bresenham's alg. to draw a line between two integer coordinates, with
 * some hacky antialiasing in there */

void draw_ptr(SDL_Surface *surface, int x1, int y1, int x2, int y2, const Uint32 needle_col, const Uint32 aa_col)
{
	int deltax = abs(x2 - x1);
	int deltay = abs(y2 - y1);
	int x = x1;
	int y = y1;
	int xinc1, xinc2;
	int yinc1, yinc2;
	int den, num;
	int numadd, numpixels, curpixel;

	if (x2 >= x1) {
		xinc1 = 1;
		xinc2 = 1;
	} else {
		xinc1 = -1;
		xinc2 = -1;
	}

	if (y2 >= y1) {
		yinc1 = 1;
		yinc2 = 1;
	} else {
		yinc1 = -1;
		yinc2 = -1;
	}

	if (deltax >= deltay) {
		xinc1 = 0;
		yinc2 = 0;
		den = deltax;
		num = deltax / 2;
		numadd = deltay;
		numpixels = deltax;
	} else {
		xinc2 = 0;
		yinc1 = 0;
		den = deltay;
		num = deltay / 2;
		numadd = deltax;
		numpixels = deltay;
	}

	if (SDL_MUSTLOCK(surface)) {
		if (SDL_LockSurface(surface) < 0) {
			return;
		}
	}
	for (curpixel = 0; curpixel <= numpixels; curpixel++) {
		set_rgba(surface, x, y, needle_col);
		num += numadd;
		if (num >= den) {
			num -= den;
			x += xinc1;
			y += yinc1;
			set_rgba(surface, x, y, aa_col);
		} else {
			set_rgba(surface, x+1, y, aa_col);
		}
		x += xinc2;
		y += yinc2;
	}
	if (SDL_MUSTLOCK(surface)) {
		SDL_UnlockSurface(surface);
	}
}
