#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "find_image.h"

SDL_Surface *find_image(char *filename)
{
	const char *uninst_path = "../graphics";
	char tmp[256];
	SDL_Surface *image;

       	/* Look in install path */
       	snprintf(tmp, 255, "%s/%s", PKG_DATA_DIR, filename);
	image = IMG_Load(tmp);
	if (image == NULL) {
		/* Fallback to uninstalled path */
		snprintf(tmp, 255, "%s/%s", uninst_path, filename);
		image = IMG_Load(tmp);
	}
	if (image == NULL) {
		fprintf(stderr, "Can't find image '%s'\n", filename);
		fprintf(stderr, "Looked in %s and %s\n", PKG_DATA_DIR, uninst_path);
		exit(1);
	}

	return image;
}
