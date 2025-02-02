

#ifndef OSC_H
#define OSC_H

#include "audio_tools.h"

class Osc
{
 protected:
  int _samplerate;
  float _freq;
  int _pos;
  int _period;

 public:
  Osc();

  void setSamplerate(int sr);
  virtual void setFreq(float f);
  virtual float stepOsc() = 0;
};

class SineOsc : public Osc
{
 private:
  float _scale;

 public:
  SineOsc();

  void setFreq(float f);
  float stepOsc();
};

class SquareOsc : public Osc
{
 private:
  float _val;
  int _halfPeriod;

 public:
  SquareOsc();

  void setFreq(float f);
  float stepOsc();
};

class TriangleOsc : public Osc
{
 private:
  bool _asc;
  int _halfPeriod;
  int _quartPeriod;

 public:
  TriangleOsc();

  void setFreq(float f);
  float stepOsc();
};


#endif


/* osc.h ends here */
