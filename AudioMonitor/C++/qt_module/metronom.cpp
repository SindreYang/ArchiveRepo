
#include <math.h>
#include "metronom.h"
#include "../algorithms_sever/audio_tools.h"

Metronom::Metronom()
{
  _wave=NULL;
  _size=0;
  _loaded=_playing=false;
  _samplerate=0;
  _offset=0;
  _bpm=120;
  _beatsPerBar=4;
  _beatLength=4;
}
Metronom::~Metronom()
{
  if (_wave)
    free(_wave);
}
void Metronom::setSamplerate(int sr)
{
  _samplerate=sr;
  generateMetroWave(_bpm, _beatsPerBar, _beatLength);
}
void Metronom::generateMetroWave(int bpm, int beats_per_bar, int beat_length)
{
  _bpm=bpm;
  _beatsPerBar=beats_per_bar;
  _beatLength=beat_length;
  if (!_samplerate)
    return;
  if (_wave)
    free(_wave);
  float beat=(float)(4 * beats_per_bar) / (float)beat_length;
  float res=(beat * 60.0) / (float)bpm;
  _size=res * _samplerate;
  _wave=(float*)malloc(sizeof(float) * _size);
  memset(_wave, 0, _size * sizeof(float)); 
  int tone_length=(_size / beats_per_bar) / 2;
  int interval=(60.0 / (float)bpm) * (4.0 / (float)beat_length) * _samplerate;
  if ((interval * (beats_per_bar-1) + tone_length) >= _size) {
    qDebug()<<"something wrong in metronom compute...";
    return;
  }
  float scale= 2 * PI * 880 / _samplerate;
  int i, j, pos;

  float max_amp=0.5;
  int attack_percent = 1, decay_percent = 10;
  int attack_length = tone_length * attack_percent / 100;
  int decay_length = tone_length * decay_percent / 100;

  float *amp=(float*)malloc(sizeof(float) * tone_length);
  for (i=0; i < attack_length; i++) {
    amp[i]=max_amp * i / ((double) attack_length);
  }
  for (i=attack_length; i < (int)tone_length - decay_length; i++) {
    amp[i]=max_amp;
  }
  for (i=(int)tone_length - decay_length; i < (int)tone_length; i++) {
    amp[i]=-max_amp * (i - (double) tone_length) / ((double) decay_length);
  }

  for (i=0; i < beats_per_bar; i++) {
    if (i == 1)
      scale= 2 * PI * 440 / _samplerate;
    pos=i * interval;
    for (j=0; j < tone_length; j++)
      _wave[pos + j]=sin(scale * j) * amp[j];
  }
  free(amp);
  qDebug()<<"[Metronom] metronom is loaded"<<_bpm<<"bpm"<<_beatsPerBar<<"/"<<_beatLength;
  _loaded=true;
}
void Metronom::setTimeBase(int bpm, int beats_per_bar, int beat_length)
{
  if ((bpm != _bpm) || (beats_per_bar != _beatsPerBar) || 
      (beat_length != _beatLength)) {
    if (_playing) {
      _mutex.lock();
      _loaded=false;
      _mutex.unlock();
    }
    generateMetroWave(bpm, beats_per_bar, beat_length);
  }
}
void Metronom::toggleMetronom(bool play)
{
  _playing=play;
}
void Metronom::setOffset(int o)
{
  _offset=o % _size;
}
float Metronom::stepMetronom()
{
  float val=0;
  _mutex.lock();
  if (_loaded && _playing) {
    val=_wave[_offset];
    _offset=(_offset + 1) % _size;
  }
  _mutex.unlock();
  return val;
}
void Metronom::processBuffers(float *buf1, float *buf2, int size)
{
  _mutex.lock();
  if (_loaded && _playing) {
    for (int i=0; i < size; i++) {
      buf1[i]+=_wave[_offset];
      buf2[i]+=_wave[_offset];
      _offset=(_offset + 1) % _size;
    }
  }
  _mutex.unlock();
}

//
MetronomWidget::MetronomWidget()
{
  setTitle("Metronom");
  _toggler.setText("OFF");
  _toggler.setCheckable(true);
  QHBoxLayout *lo=new QHBoxLayout;
  lo->addWidget(&_toggler);
  setLayout(lo);
  connect(&_toggler, SIGNAL(toggled(bool)), 
	  this, SLOT(metronomToggled(bool)));
}
void MetronomWidget::metronomToggled(bool on)
{
  if (on)
    _toggler.setText("ON");
  else
    _toggler.setText("OFF");

  _metronom.toggleMetronom(on);
}

// 
// metronom.cpp ends here
