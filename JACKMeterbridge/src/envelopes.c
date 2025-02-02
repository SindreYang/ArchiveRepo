#include <math.h>
#include <jack/jack.h>

#include "main.h"
#include "envelopes.h"

float rms_buffers[MAX_METERS][RMS_BUF_SIZE];
float rms_sums[MAX_METERS];
float ring_buf[MAX_METERS][RING_BUF_SIZE];
unsigned int rms_pos = 0;

float env_read(int port)
{
	float tmp = env[port];
	env[port] = 0.0f;

	return tmp;
}

int process_peak(jack_nframes_t nframes, void *arg)
{
	unsigned int i, port;

	if (meter_freeze) {
		return 0;
	}

	for (port = 0; port < num_meters; port++) {
		jack_default_audio_sample_t *in, *out;

		/* just incase the port isn't registered yet */
		if (input_ports[port] == 0 || output_ports[port] == 0) {
			break;
		}

		in = (jack_default_audio_sample_t *) jack_port_get_buffer(input_ports[port], nframes);
		out = (jack_default_audio_sample_t *) jack_port_get_buffer(output_ports[port], nframes);

		for (i = 0; i < nframes; i++) {
			const float s = fabs(in[i]);
			out[i] = in[i];
			if (s > env[port]) {
				env[port] = s;
			}
		}
	}

	return 0;
}

void init_buffers_rms()
{
	unsigned int i, j;

	for (i=0; i < MAX_METERS; i++) {
		rms_sums[i] = 0.0f;
		for (j=0; j < RMS_BUF_SIZE; j++) {
			rms_buffers[i][j] = 0.0f;
		}
	}
}

int process_rms(jack_nframes_t nframes, void *arg)
{
	unsigned int i, port;

	if (meter_freeze) {
		return 0;
	}

	for (port = 0; port < num_meters; port++) {
		jack_default_audio_sample_t *in, *out;

		/* just incase the port isn't registered yet */
		if (input_ports[port] == 0 || output_ports[port] == 0) {
			break;
		}

		in = (jack_default_audio_sample_t *) jack_port_get_buffer(input_ports[port], nframes);
		out = (jack_default_audio_sample_t *) jack_port_get_buffer(output_ports[port], nframes);

		/* Update running total of samples in RMS buffer */
		for (i = 0; i < nframes; i++) {
			const float s = in[i] * in[i];
			out[i] = in[i];
			rms_sums[port] -= rms_buffers[port][rms_pos];
			rms_sums[port] += s;
			rms_buffers[port][rms_pos] = s;
			rms_pos = (rms_pos + 1) & (RMS_BUF_SIZE - 1);

		} if (rms_sums[port] < 0.0f) {
			/* This should never happnen, but can occasionally due
			 * the the difference between the rms history and the
			 * float sum. We clobber it just to make sure. */
			rms_sums[port] = 0.0f;
	       	}
	       	env[port] = sqrtf(rms_sums[port] / (float)RMS_BUF_SIZE); }

	return 0;
}

int process_ring(jack_nframes_t nframes, void *arg)
{
	static unsigned int pos = 0;
	unsigned int i, port;
	jack_default_audio_sample_t *in, *out;

	if (meter_freeze) {
		return 0;
	}

	for (port = 0; port < num_meters; port++) {
		/* just incase the port isn't registered yet */
		if (input_ports[port] == 0 || output_ports[port] == 0) {
			break;
		}

		in = (jack_default_audio_sample_t *) jack_port_get_buffer(input_ports[port], nframes);
		out = (jack_default_audio_sample_t *) jack_port_get_buffer(output_ports[port], nframes);
		for (i=0; i<nframes; i++) {
			out[i] = in[i];
			ring_buf[port][(pos + i) & (RING_BUF_SIZE - 1)] = in[i];
		}
	}
	pos = (pos + nframes) & (RING_BUF_SIZE - 1);

	return 0;
}
