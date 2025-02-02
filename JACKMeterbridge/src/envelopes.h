#ifndef ENVELOPES_H
#define ENVELOPES_H

#include <jack/jack.h>

#define RMS_BUF_SIZE 256
#define RING_BUF_SIZE 1024

extern float ring_buf[MAX_METERS][RING_BUF_SIZE];

float env_read(int port);

int process_peak(jack_nframes_t nframes, void *arg);
int process_rms(jack_nframes_t nframes, void *arg);
int process_ring(jack_nframes_t nframes, void *arg);
void init_buffers_rms();

#endif
