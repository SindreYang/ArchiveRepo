
#ifndef AUDIO_TOOLS_H
#define AUDIO_TOOLS_H

#include <math.h>

#define PI	3.14


float getDbVal(float val);
float dB_to_multiplier(float  dB);
float multiplier_to_dB(float multiplier);

float getDbPercent(float db);
float hard_clip(float val, float min, float max);
float tau(float *x, float *y, unsigned int n);
void trace(int columns ,int  &x, int &y);
void  tay_lp(int columns,int &w,char &c );
#endif

/* audio_tools.h ends here */
