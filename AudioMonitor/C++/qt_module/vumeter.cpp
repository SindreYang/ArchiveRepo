#include <math.h>
#include "vumeter.h"

Vu::Vu()
{
  setMinimumSize(10, 10);
  setOrientation(Qt::Vertical);
  setRange(0, 70); //100?70
  _peak=0;
  setValue(60);
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
  setPeak(0);
}
void Vu::refresh()
{
  setPeak(_peak);
  _peak=0;
}
void Vu::setPeak(float peak)
{
  setValue((float)getDbPercent(getDbVal(peak)));
}
void Vu::processValue(float val)
{
  float vuval;
  vuval=fabs(val);
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
    painter.setBrush(QColor(2,25,17));
    painter.fillRect(rect, painter.brush());
    QLinearGradient linGrad2(0, rect.y(), rect.width(), rect.height());
    linGrad2.setColorAt(rv, Qt::red);
    linGrad2.setColorAt(yv, Qt::yellow);
    linGrad2.setColorAt(gv, Qt::green);
    linGrad2.setColorAt(bv, Qt::blue);
    linGrad2.setSpread(QGradient::PadSpread);
    painter.setBrush(linGrad2);
    float evol=(float)getDbPercent(getDbVal(_peak)) / ((float)maximum()+1);//修正0刻度误差,所以加1;
    r.setRect(0, rect.height()-(evol*rect.height())+rect.y(), rect.width(), rect.height());
    painter.drawRect(r);


}

//
MeterStrip::MeterStrip()
{
    setMinimumWidth(20);
    _orientation=Qt::Vertical;
}

void MeterStrip::paintEvent(QPaintEvent *event)
{
    QRect rect=event->rect();
    QPalette p=palette();
    QPainter painter(this);
    int  db_points[] = {60, 50, 40, 30,25,20,15, 10, 5, 0,};
    painter.setPen(QColor(169,169,169));
    painter.setFont(QFont("Times", 9, QFont::Bold));
    int pos;
    //for(int i=0;i<=70;i++){qDebug()<<i<<getDbPercent(-i);}
    if( _orientation==Qt::Vertical){

        for (int val : db_points) {

            pos=(int)(height() - fabs(height() * (getDbPercent(-val)/71)));//不用70,原因是为了让0刻度显示出来;
            //for (int i=70;i>=0;i--) { int pos_i=(int)(height() - fabs(height() * (getDbPercent(-i)/71)));painter.drawLine(0,pos_i,2,pos_i);}
            painter.drawLine(0,pos,6,pos);
            //if(val==0){painter.drawText(5,pos-5,width(),height(), Qt::AlignLeft, QString("%1").arg(val));}
            //else{painter.drawText(5,pos-5,width(),height(), Qt::AlignLeft, QString("%1").arg(val));}
            painter.drawText(7,pos-5,width(),height(), Qt::AlignLeft, QString("%1").arg(val));

        }
        //painter.drawText(0,height(),width(),height(), Qt::AlignLeft,QString("-%1").arg("∞"));
    }else{

        for (int val : db_points) {
            pos=(int)(height() - fabs(height()* (getDbPercent(-val)/71)));
            //qDebug()<<val<<pos<<getDbPercent(-val);
            //for (int i=70;i>=0;i--) { int pos_i=(int)(height() - fabs(height() * (getDbPercent(-i)/71)));painter.drawLine(width()-2,pos_i,width(),pos_i);}
            painter.drawLine(width()-5,pos,width(),pos);
            //if(val==0){painter.drawText(-5,pos-5,width(),height(), Qt::AlignRight, QString("%1").arg(val));}
            //else{painter.drawText(-5,pos-5,width(),height(),Qt::AlignRight, QString("%1").arg(val));}
            painter.drawText(-4,pos-5,width(),height(),Qt::AlignRight, QString("%1").arg(val));
        }
       //painter.drawText(0,height()-10,width(),height(), Qt::AlignRight, QString("%1-").arg("∞"));
    }
}
PhaseStrip::PhaseStrip()
{
    setMaximumHeight(15);
}
PhaseStrip::~PhaseStrip()
{

}
void PhaseStrip::paintEvent(QPaintEvent *event)
{
    QRect rect=event->rect();
    //printf("PhaseStrip相位::%.1f\n",bottomVal);
    QPalette p=palette();
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.fillRect(rect, painter.brush());
    //painter.setPen(QPen(QColor("#0c3d6e"),2));
    //painter.drawRect(0,0,rect.width(),rect.height());
    //底部渐变色
    QLinearGradient linGrad2(0, height(), width(), height());
    linGrad2.setColorAt(0, Qt::red);
    linGrad2.setColorAt(1, Qt::green);
    linGrad2.setSpread(QGradient::PadSpread);
    painter.setBrush(linGrad2);
    double bV= bottomVal;
    double bottomBar= width()/2 * bV;
    QRectF bar6(width()/2, 0,bottomBar, height());
    painter.drawRect(bar6);
    QRectF bottom(0, 0,width(), height());
    painter.setPen(QPen(QColor(169,169,169), 5));
    painter.drawText(bottom,Qt::AlignRight, "+1");
    painter.drawText(bottom,Qt::AlignCenter, "0");
    painter.drawText(bottom,Qt::AlignLeft, "-1");



}

StereoVuMeter::StereoVuMeter()
{
    _meterLeft.setOrientation(Qt::Horizontal);
    QHBoxLayout *lo_left=new QHBoxLayout;
    lo_left->addWidget(&_meterLeft);
    lo_left->addWidget(&_vuLeft);

    lo_left->setContentsMargins(0, 0, 0, 0);
    lo_left->setMargin(0);
    lo_left->setSpacing(0);
    QHBoxLayout *lo_right=new QHBoxLayout;
    lo_right->addWidget(&_vuRight);
    lo_right->addWidget(&_meterRight);
    lo_right->setContentsMargins(0, 0, 0, 0);
    lo_right->setMargin(0);
    lo_right->setSpacing(0);
    QHBoxLayout *lo=new QHBoxLayout;
    lo->addLayout(lo_left);
    lo->addLayout(lo_right);
    lo->setContentsMargins(0, 0, 0, 0);
    lo->setMargin(0);

    QVBoxLayout *l1=new QVBoxLayout;
    l1->addLayout(lo);
    l1->addWidget(&_phase);
    l1->setContentsMargins(0, 0, 0, 0);
    l1->setSpacing(5);//上下边距
    l1->setMargin(0);//与窗体左右边距
    l1->setSizeConstraint(QLayout::SetMaximumSize);
    setLayout(l1);

}

StereoVuMeter::~StereoVuMeter()
{
  delete layout();
}
void StereoVuMeter::refresh()
{
    //printf("相位::%.1f\n",_phase.getbottomVal());
    _vuLeft.refresh();
    _vuRight.refresh();
    _phase.refresh();



}
void StereoVuMeter::setOrientation(Qt::Orientation o)
{
  delete layout();
  _vuLeft.setOrientation(o);
  _vuRight.setOrientation(o);
  _meterRight.setOrientation(o);
  if (o == Qt::Vertical) {
    QHBoxLayout *lo=new QHBoxLayout;
    lo->addWidget(&_vuLeft);
    lo->addWidget(&_vuRight);
    lo->addWidget(&_meterRight);
    lo->setContentsMargins(0, 0, 0, 0);
    setLayout(lo);
  }
  else {
    QVBoxLayout *lo=new QVBoxLayout;
    lo->addWidget(&_vuLeft);
    lo->addWidget(&_vuRight);
    lo->addWidget(&_meterRight);
    lo->setContentsMargins(0, 0, 0, 0);
    setLayout(lo);
  }
}

void StereoVuMeter::setvurgb( int r,int y,int g,int b)
{
    float rf=getDbPercent(-r)/70;
    float yf=getDbPercent(-y)/70;
    float gf=getDbPercent(-g)/70;
    float bf=getDbPercent(-b)/70;
    _vuLeft.setvurgb(rf,yf,gf,bf);
    _vuRight.setvurgb(rf,yf,gf,bf);
//    qDebug()<<r<<y<<g<<b;
//    qDebug()<<rf<<yf<<gf<<bf<<getDbPercent(-r);
}
