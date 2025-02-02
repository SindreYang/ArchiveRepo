#ifndef MAIN_H
#define MAIN_H

#include <SDL.h>
#include <jack/jack.h>

#define MAX_METERS 32

extern SDL_Surface *screen;
extern SDL_Surface *image, *meter, *meter_buf;
//extern SDL_Rect win, buf_rect[MAX_METERS], dest[MAX_METERS];
extern SDL_Rect win,  dest[MAX_METERS];
extern jack_port_t *input_ports[MAX_METERS];
extern jack_port_t *output_ports[MAX_METERS];

extern int num_meters;
extern int num_scopes;
extern int meter_freeze;
extern float env[MAX_METERS];

extern float bias;

#endif
