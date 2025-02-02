#ifndef VUMETER_H
#define VUMETER_H

#include <QtGui>
#include "../algorithms_sever/audio_tools.h"
#include <QtWidgets>
#include <QLabel>
class Vu : public QProgressBar
{
  Q_OBJECT
public:
  Vu();
  void setOrientation(Qt::Orientation);
  void reset();
  void processValue(float val);
  void processBuffer(float *buf, int size);
  float getpeak(){return getDbVal(_peak);}
  float rv=0.0;
  float yv=0.4;
  float gv=0.8;
  float bv=1.0;

public slots:
  void refresh();
  void setvurgb( float r,float y,float g,float b){rv=r;yv=y;gv=g;bv=b;}

private:
  float _peak=0.;
  void setPeak(float val);
  void paintEvent( QPaintEvent* event );

};

class MeterStrip : public QWidget
{
  Q_OBJECT
private:
  Qt::Orientation _orientation;
  void paintEvent( QPaintEvent* event );

public:
  MeterStrip();
  void setOrientation(Qt::Orientation o) {_orientation=o;}

};
class PhaseStrip : public QWidget
{
    Q_OBJECT
private:
    void paintEvent( QPaintEvent* event );
    double bottomVal=0;

public:
    PhaseStrip();
    ~PhaseStrip();
    void setbottomVal(double Val){bottomVal=Val;update();}
    double getbottomVal(){return bottomVal;}
public slots:
     void refresh(){bottomVal=0;}

};



class StereoVuMeter : public QWidget
{
  Q_OBJECT
 private:
      PhaseStrip _phase;
      Vu _vuLeft, _vuRight;
      MeterStrip _meterRight,_meterLeft;


 public:
  StereoVuMeter();
  ~StereoVuMeter();
  void setOrientation(Qt::Orientation o);
  void reset() {_vuLeft.reset();_vuRight.reset();}
  void processLeftValue(float val) {_vuLeft.processValue(val);  /*getLeftValue()*/;}//多线程.不然要闪屏
  void processRightValue(float val) {_vuRight.processValue(val); /*getRightValue()*/;}
  void processBuffers(float *buf1, float *buf2, int size) {_vuLeft.processBuffer(buf1, size);_vuRight.processBuffer(buf2, size);getLeftValue();getRightValue();}
  void processphaseValue(float val) {_phase.setbottomVal(val); }
  double getphaseValue() {return _phase.getbottomVal();}
  float getLeftV() {return _vuLeft.getpeak();}
  float getRightV() {return _vuRight.getpeak();}
  void setvurgb( int r=3,int y=10,int g=48,int b=70);



 public slots:
     void refresh();
     void getLeftValue() {if(_vuLeft.getpeak()>=-70&&0>=_vuLeft.getpeak()){ emit LeftValue(int(_vuLeft.getpeak()));}}
     void getRightValue() {if(_vuRight.getpeak()>=-70&&0>=_vuRight.getpeak()){ emit RightValue(int(_vuRight.getpeak()));}}
Q_SIGNALS:
     void LeftValue(int);
     void RightValue(int);
};

#endif
