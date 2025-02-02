

#ifndef METRONOM_H
#define METRONOM_H

#include <QtGui>
#include <QtWidgets>
#include <QLabel>

class Metronom : public QObject
{
Q_OBJECT
 private:
  float *_wave;
  int _offset;
  int _size;
  int _samplerate;
  bool _playing;
  int _bpm, _beatsPerBar, _beatLength;
  bool _loaded;
  QMutex _mutex;

  void generateMetroWave(int bpm, int beats_per_bar, int beat_length);

 public:
  Metronom();
  ~Metronom();

  void setSamplerate(int sr);
  void toggleMetronom(bool);
  void setOffset(int);
  float stepMetronom();
  void processBuffers(float *buf1, float *buf2, int size);

 public slots:
  void setTimeBase(int bpm, int beats_per_bar, int beat_length);
};

class MetronomWidget : public QGroupBox
{
Q_OBJECT
 private:
  Metronom _metronom;
  QPushButton _toggler;
  
 private slots:
  void metronomToggled(bool);

 public:
  MetronomWidget();

  void setSamplerate(int sr) {_metronom.setSamplerate(sr);}
  void setOffset(int o) {_metronom.setOffset(o);}
  float stepMetronom() {return _metronom.stepMetronom();}
  void processBuffers(float *buf1, float *buf2, int size) {_metronom.processBuffers(buf1, buf2, size);}

 public slots:
  void setTimeBase(int bpm, int bpb, int bl) {_metronom.setTimeBase(bpm, bpb, bl);}
};

#endif
/* metronom.h ends here */
