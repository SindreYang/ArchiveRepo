#include <math.h>
#include "vumeter.h"

Vu::Vu()
{
  setMinimumSize(10, 10);
  setOrientation(Qt::Vertical);
  setRange(-70, 0);
  _peak=-70;
  setValue(-50);
}
void Vu::setOrientation(Qt::Orientation o)
{
  QProgressBar::setOrientation(o);
  if (o != Qt::Vertical)
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
  else
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
}
void Vu::reset()
{
  setPeak(-70);
}
void Vu::refresh()
{
  setPeak(_peak);
  _peak=-70;
}
void Vu::setPeak(float peak)
{
        //qDebug()<<"setpeak:"<<getDbVal(peak);
        setValue((int)getDbPercent(getDbVal(peak)));
}
void Vu::processValue(float val)
{
  float vuval;

  //vuval=fabs(val);
  vuval=val;
  //qDebug()<<vuval<<_peak;
  if (vuval > _peak)
    _peak=vuval;
}
void Vu::processBuffer(float *buf, int size)
{
  for (int i=0; i < size; i++)
    processValue(buf[i]);

}
void Vu::paintEvent(QPaintEvent *event)
{
    QRect rect=event->rect();

    QPalette p=palette();
    QPainter painter(this);
    QRectF r;
    painter.setBrush(Qt::black);
    painter.fillRect(rect, painter.brush());
    float evol=(float)value() / (float)(-70)  ;//最大值
    Qt::Orientation ori=orientation();
    int _brickResolution;
    float brickHeight, brickWidth;
    if (ori == Qt::Vertical) {
    _brickResolution=height() / 3;
    brickWidth=width() - 2;
    brickHeight=3;//(float)height() / (float)_brickResolution;
    }
    else {
    _brickResolution=width() / 3;
    brickHeight=height() - 2;
    brickWidth=3;//(float)width() / (float)_brickResolution;
    }
    int brickCount=(int)(evol * _brickResolution);
    QLinearGradient linGrad2(0, 0, 0, height());
    linGrad2.setColorAt(0, Qt::red);
    linGrad2.setColorAt(0.5, Qt::yellow);
    linGrad2.setColorAt(1, Qt::green);
    linGrad2.setSpread(QGradient::PadSpread);
    painter.setBrush(linGrad2);
    if (ori == Qt::Vertical){
        r.setRect(1, height()-brickHeight*brickCount, brickWidth, height());
      }
    else{
          r.setRect(brickWidth * brickCount, 1, width(), brickHeight);
        }

    painter.drawRect(r);


}
PhaseStrip::PhaseStrip()
{
    setMinimumSize(50, 5);
    setMaximumSize(200,20);
}
void PhaseStrip::paintEvent(QPaintEvent *event)
{
    QRect rect=event->rect();

    QPalette p=palette();
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.fillRect(rect, painter.brush());
    // 底部渐变色

    QLinearGradient linGrad2(0, height(), width(), height());
    linGrad2.setColorAt(0, Qt::red);
    linGrad2.setColorAt(1, Qt::green);
    linGrad2.setSpread(QGradient::PadSpread);
    painter.setBrush(linGrad2);
    double bottomBar= width()/2 * bottomVal;
    QRectF bar6(width()/2, 0,bottomBar, height());
    painter.drawRect(bar6);


    QRectF bottom(0, 0,width(), height());
    painter.setPen(QPen(QColor(255, 255, 255), 5));
    painter.drawText(bottom,Qt::AlignRight, "+1");
    painter.drawText(bottom,Qt::AlignCenter, "0");
    painter.drawText(bottom,Qt::AlignLeft, "-1");


}
MeterStrip::MeterStrip()
{
  setMinimumSize(20, 10);
  _orientation=Qt::Vertical;
}

void MeterStrip::paintEvent(QPaintEvent *event)
{
  QRect rect=event->rect();

  QPalette p=palette();
  QPainter painter(this);
  int  db_points[] = {-60, -50, -40, -30, -20, -15, -6, -4, -2, 0};
  //painter.setBrush(QColor(71, 71, 71));
  //painter.fillRect(rect, painter.brush());
  //painter.setPen(Qt::white);
  QFont ft("Times");
  ft.setPixelSize(8);
  painter.setFont(ft);
  int pos;
  for (uint i=0; i < sizeof (db_points)/sizeof (db_points[0]); i++) {
    if (_orientation == Qt::Vertical) {
      pos=(int)(height() - fabs(height() * (getDbPercent(db_points[i])/70)));
      //qDebug()<<db_points[i]<<pos<<getDbPercent(db_points[i]);
      if (db_points[i] > 0)
        painter.drawText(2, pos, QString("%1").arg(db_points[i]));
      else
        painter.drawText(2, pos, QString("%1").arg(db_points[i]));
    }
    else {
      pos=(int)(width() * (getDbPercent(db_points[i])/100));
      if (db_points[i] > 0)
        painter.drawText(pos, 10, QString("+%1").arg(db_points[i]));
      else
        painter.drawText(pos, 10, QString("%1").arg(db_points[i]));
    }
  }
}

//
VuMeter::VuMeter()
{
  QHBoxLayout *lo=new QHBoxLayout;
  lo->addWidget(&_vu);
  lo->addWidget(&_meter);
  lo->setContentsMargins(0, 0, 0, 0);
  setLayout(lo);
}
VuMeter::~VuMeter()
{
  delete layout();
}
void VuMeter::setOrientation(Qt::Orientation o)
{
  delete layout();
  _vu.setOrientation(o);
  _meter.setOrientation(o);
  if (o == Qt::Vertical) {
    QHBoxLayout *lo=new QHBoxLayout;
    lo->addWidget(&_vu);
    lo->addWidget(&_meter);
    lo->setContentsMargins(0, 0, 0, 0);
    setLayout(lo);
  }
  else {
    QVBoxLayout *lo=new QVBoxLayout;
    lo->addWidget(&_vu);
    lo->addWidget(&_meter);
    lo->setContentsMargins(0, 0, 0, 0);
    setLayout(lo);
  }
}

//
StereoVuMeter::StereoVuMeter()
{
  QHBoxLayout *lo=new QHBoxLayout;
  lo->addWidget(&_meterLeft);
  lo->addWidget(&_vuLeft);
  lo->addWidget(&_vuRight);
  lo->addWidget(&_meter);
  lo->setContentsMargins(0, 0, 0, 0);
  //setLayout(lo);
  QVBoxLayout *l1=new QVBoxLayout;
  l1->addLayout(lo);
  l1->addWidget(&_phase);
  setLayout(l1);
}
StereoVuMeter::~StereoVuMeter()
{
  delete layout();
}
void StereoVuMeter::setOrientation(Qt::Orientation o)
{
  delete layout();
  _vuLeft.setOrientation(o);
  _vuRight.setOrientation(o);
  _meter.setOrientation(o);
  if (o == Qt::Vertical) {
    QHBoxLayout *lo=new QHBoxLayout;
    lo->addWidget(&_vuLeft);
    lo->addWidget(&_vuRight);
    lo->addWidget(&_meter);
    lo->setContentsMargins(0, 0, 0, 0);
    setLayout(lo);
  }
  else {
    QVBoxLayout *lo=new QVBoxLayout;
    lo->addWidget(&_vuLeft);
    lo->addWidget(&_vuRight);
    lo->addWidget(&_meter);
    lo->setContentsMargins(0, 0, 0, 0);
    setLayout(lo);
  }
}
