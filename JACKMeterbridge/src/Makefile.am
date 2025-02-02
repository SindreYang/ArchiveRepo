#CFLAGS = -O6 `sdl-config --cflags` -DPKG_DATA_DIR=\"$(pkgdatadir)\"
CFLAGS = -Wall -g $(SDL_CFLAGS) $(JACK_CFLAGS) -DPKG_DATA_DIR=\"$(pkgdatadir)\"

bin_PROGRAMS = meterbridge

EXTRA_DIST = *.h

meterbridge_SOURCES = main.c linedraw.c vu_meters.c ppm_meters.c dpm_meters.c jf_meters.c scope.c envelopes.c find_image.c
meterbridge_LDFLAGS = -lm $(JACK_LIBS) $(SDL_LIBS) -lSDL_image
