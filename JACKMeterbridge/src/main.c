#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>
#include <jack/jack.h>
#include <getopt.h>

#include "config.h"
#include "main.h"
#include "envelopes.h"
#include "find_image.h"

#include "vu_meters.h"
#include "ppm_meters.h"
#include "dpm_meters.h"
#include "jf_meters.h"
#include "scope.h"

#define MET_VU  1 // The meter display type
#define MET_PPM 2
#define MET_DPM 3
#define MET_JF  4
#define MET_SCO 5

void make_channel(jack_client_t *client, int i, char *port_name);
void cleanup(void);
int store(char *path, void *data);

SDL_Thread *gt;
SDL_Surface *screen;
SDL_Surface *background_image, *meter, *meter_buf;
SDL_Rect win, dest[MAX_METERS];

int num_meters = 0;
int num_scopes = 0;
int meter_freeze = 0;
float env[MAX_METERS];

char *meter_name = "ppm";
char client_name[256];

float bias = 1.0f; // To allow for ref level changes

jack_port_t *input_ports[MAX_METERS];
jack_port_t *output_ports[MAX_METERS];
jack_client_t *client;

int main(int argc, char *argv[])
{
	SDL_Event event;
	unsigned int i;
	int opt;
	float ref_lev;
	int port_base = 1;
	unsigned int meter_type = MET_PPM;
	int columns = MAX_METERS;
	int x = 0, y = 0;
	char window_name[256];
	char *us_client_name = NULL;

	num_meters = argc;
	while ((opt = getopt(argc, argv, "t:r:c:n:h")) != -1) {
		switch (opt) {
			case 'r':
				ref_lev = atof(optarg);
				printf("Reference level: %.1fdB\n", ref_lev);
				bias = powf(10.0f, ref_lev * -0.05f);
				port_base += 2;
				break;
			case 't':
				if (!strcmp(optarg, "vu")) {
					meter_type = MET_VU;
				} else if (!strcmp(optarg, "ppm")) {
					meter_type = MET_PPM;
				} else if (!strcmp(optarg, "dpm")) {
					meter_type = MET_DPM;
				} else if (!strcmp(optarg, "jf")) {
					meter_type = MET_JF;
				} else if (!strcmp(optarg, "sco")) {
					meter_type = MET_SCO;
				} else {
					fprintf(stderr, "Unknown meter type: %s\n", optarg);
					exit(1);
				}
				meter_name = optarg;
				port_base += 2;
				break;
			case 'c':
				columns = atoi(optarg);
				port_base += 2;
				break;
			case 'n':
				us_client_name = strdup(optarg);
				port_base += 2;
				break;
			case 'h':
				/* Force help to be shown */
				num_meters = 0;
				break;
			default:
				num_meters = 0;
				break;
		}
	}
	num_meters -= port_base;

	if (num_meters > MAX_METERS) {
		num_meters = MAX_METERS;
	}

	if (meter_type == MET_JF) {
		if (num_meters % 2 != 0) {
			fprintf(stderr, "WARNING: Jellyfish meters require an even number of inputs.\n");
		}
		num_scopes = num_meters / 2;
	} else {
		num_scopes = num_meters;
	}

	if (num_meters < 1) {
		fprintf(stderr, "Meterbridge version %s - http://plugin.org.uk/meterbridge/\n\n", VERSION);
		fprintf(stderr, "Usage %s: [-r ref-level] [-c columns] [-n jack-name] [-t type] <port>+\n\n", argv[0]);
		fprintf(stderr, "where ref-level is the reference signal level for 0dB on the meter\n");
		fprintf(stderr, "  and type is the meter type, one of:\n");
		fprintf(stderr, "     'vu'  - classic moving needle VU meter\n");
		fprintf(stderr, "     'ppm' - PPM meter\n");
		fprintf(stderr, "     'dpm' - Digital peak meter\n");
		fprintf(stderr, "     'jf'  - 'Jellyfish' phase meter\n");
		fprintf(stderr, "     'sco' - Oscilloscope meter\n");
		exit(1);
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}
	//atexit(SDL_Quit);
	//atexit(cleanup);

	for (i=0; i<num_meters; i++) {
		env[i] = 0.0f;
	}

	switch (meter_type) {
		case MET_VU:
			load_graphics_vu();
			break;
		case MET_PPM:
			load_graphics_ppm();
			break;
		case MET_DPM:
			load_graphics_dpm();
			break;
		case MET_JF:
			load_graphics_jf();
			break;
		case MET_SCO:
			load_graphics_scope();
			break;
	}
		
	if (columns > num_scopes) {
		columns = num_scopes;
	}

	/* Calculate window size */
	win.x = 0;
	win.y = 0;
	win.w = meter->w * columns;
	win.h = meter->h * (((num_scopes - 1) / columns) + 1);

	screen = SDL_SetVideoMode(win.w, win.h, 32, SDL_SWSURFACE);
	if ( screen == NULL ) {
		fprintf(stderr, "Unable to set %dx%d video: %s\n", win.w, win.h, SDL_GetError());
		exit(1);
	}

	background_image = find_image("brushed-steel.png");

	/* Draw background image */
	dest[0].w = background_image->w;
	dest[0].h = background_image->h;
	for (x=0; x < win.w; x += background_image->w) {
		for (y=0; y < win.h; y += background_image->h) {
			dest[0].x = x;
			dest[0].y = y;
			SDL_BlitSurface(background_image, NULL, screen, dest);
		}
	}

	/* Draw meter frames */
	for (i=0, x=0, y=0; i<num_scopes; i++, x++) {
		dest[i].x = meter->w * x;
		dest[i].y = meter->h * y;
		dest[i].w = meter->w;
		dest[i].h = meter->h;
		SDL_BlitSurface(meter, NULL, screen, dest+i);
		if (i % columns == columns - 1) {
			x = -1;
			y++;
		}
	}

	SDL_UpdateRects(screen, 1, &win);

	/* Register with jack */
	if (us_client_name) {
		strncpy(client_name, us_client_name, 31);
	} else {
		snprintf(client_name, 255, "bridge-%d", getpid());
	}
	if ((client = jack_client_new(client_name)) == 0) {
		fprintf(stderr, "jack server not running?\n");
		exit(1);
	}
	printf("Registering as %s\n", client_name);
	snprintf(window_name, 255, "%s %s", meter_name, client_name);
	SDL_WM_SetCaption(window_name, client_name);

	/* Start the graphics thread */
	switch (meter_type) {
		case MET_VU:
			gt = SDL_CreateThread(gfx_thread_vu, NULL);
			break;
		case MET_PPM:
			gt = SDL_CreateThread(gfx_thread_ppm, NULL);
			break;
		case MET_DPM:
			gt = SDL_CreateThread(gfx_thread_dpm, NULL);
			break;
		case MET_JF:
			gt = SDL_CreateThread(gfx_thread_jf, NULL);
			break;
		case MET_SCO:
			gt = SDL_CreateThread(gfx_thread_scope, NULL);
			break;
	}

	/* Pick the jack process method */
	if (meter_type == MET_VU) {
		init_buffers_rms();
		jack_set_process_callback(client, process_rms, 0);
	} else if (meter_type == MET_JF || meter_type == MET_SCO) {
		jack_set_process_callback(client, process_ring, 0);
	} else {
		jack_set_process_callback(client, process_peak, 0);
	}
	// This is used to maually save the session, but the auto stuff
	// does a better job anyway. Just here for testing
	//jack_set_store_callback(client, store, NULL);

	if (jack_activate(client)) {
		fprintf (stderr, "cannot activate client");
		exit(1);
	}

	/* Create and connect the jack ports */
	for (i = 0; i < num_meters; i++) {
		make_channel(client, i, argv[port_base+i]);
	}

	while (SDL_WaitEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				cleanup();
				break;
			case 5:
				meter_freeze = 1;
				break;
			case 6:
				meter_freeze = 0;
				break;
			default:
				//printf("%d\n", event.type);
				break;
		}
	}

	cleanup();

	/* We can't ever get here, but it keeps gcc quiet */
	return 0;
}

/* make_channel: Do all the jack hackery needed to wire up a single channel. An
 * input port for the meter and an output port for monitoring */

void make_channel(jack_client_t *client, int i, char *port_name)
{
	char in_name[256], out_name[256];
	jack_port_t *port;
	int flags;

	snprintf(in_name, 255, "meter_%d", i+1);
	if (!(input_ports[i] = jack_port_register(client, in_name, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0))) {
		fprintf(stderr, "Cannot register '%s'\n", in_name);
		cleanup();
	}
	snprintf(in_name, 255, "%s:meter_%d", client_name, i+1);

	snprintf(out_name, 255, "monitor_%d", i+1);
	if (!(output_ports[i] = jack_port_register(client, out_name, JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0))) {
		fprintf(stderr, "Cannot register '%s'\n", out_name);
		cleanup();
	}
	snprintf(out_name, 255, "%s:monitor_%d", client_name, i+1);
	
	//XXX doesn't work properly:
	//jack_port_tie(output_ports[i], input_ports[i]);

	//fprintf(stderr, "connecting '%s' to '%s'...\n", in_name, port_name);
	port = jack_port_by_name(client, port_name);
	if (port == NULL) {
		fprintf(stderr, "Can't find port '%s'\n", port_name);
		return;
	}
	flags = jack_port_flags(port);

	if (flags & JackPortIsInput) {
		const char **connections;
		unsigned int j;

		connections = jack_port_get_all_connections(client, port);
		for (j=0; connections && connections[j]; j++) {
			if (jack_disconnect(client, connections[j], port_name) == 0) {
				//fprintf(stderr, "Broke '%s' to '%s'\n", possible_ports[j], port_name);
				if (jack_connect(client, connections[j], in_name)) {
					fprintf(stderr, "Could not connect '%s' to '%s'\n", connections[j], in_name);
					cleanup();
				}
				//fprintf(stderr, "Connected '%s' to '%s'\n", possible_ports[j], in_name);
			} else {
				fprintf(stderr, "Could not disconnect %s\n", connections[j]);
			}
		}
		free(connections);
		jack_connect(client, out_name, port_name);
		//fprintf(stderr, "Connected '%s' to '%s'\n", out_name, port_name);
	} else if (flags & JackPortIsOutput && jack_connect(client, port_name, jack_port_name(input_ports[i]))) {
		fprintf(stderr, "Cannot connect port '%s' to '%s'\n", port_name, in_name);
		cleanup();
	}
}

void cleanup()
{
	unsigned int i, j, l;
	const char **all_iports, **all_oports;

	//printf("cleanup()\n");

	for (i=0; i<num_meters; i++) {
		if (input_ports[i] == NULL || output_ports[i] == NULL) {
			continue;
		}

		all_iports = jack_port_get_all_connections(client,
				output_ports[i]);
		all_oports = jack_port_get_all_connections(client,
				input_ports[i]);

		for (j=0; all_oports && all_oports[j]; j++) {
			jack_disconnect(client, all_oports[j], jack_port_name(input_ports[i]));
		}

		for (j=0; all_iports && all_iports[j]; j++) {
			jack_disconnect(client, jack_port_name(output_ports[i]), all_iports[j]);
			for (l=0; all_oports && all_oports[l]; l++) {
				jack_connect(client, all_oports[l], all_iports[j]);
			}
		}
	}

	/* Leave the jack graph */
	jack_client_close(client);

	/* Get rid of the GUI stuff */
	SDL_KillThread(gt);
	SDL_Quit();

	/* And were done */
	exit(0);
}

int store(char *path, void *data)
{
	char cmdpath[256];
	int i;
	FILE *cmd;

	printf("Store request received: %s\n", path);
	snprintf(cmdpath, 255, "%s/start", path);
	if (!(cmd = fopen(cmdpath, "w"))) {
		printf("Cannot store state in '%s'\n", cmdpath);
		return 0;
	}
	fprintf(cmd, "meterbridge -n '%s' -t %s ", client_name, meter_name);
	for (i=0; i<num_meters; i++) {
		fprintf(cmd, " -");
	}
	fprintf(cmd, "\n");
	fclose(cmd);

	return 0;
}
