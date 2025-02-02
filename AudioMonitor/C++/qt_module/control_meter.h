

#ifndef CONTROL_METER_H
#define CONTROL_METER_H

#include "vumeter.h"
#include "midi_widgets.h"
#include <QQueue>

class Coordinate_Fader: public QSlider
{
    Q_OBJECT
public:
    Coordinate_Fader();
    float getParamValue();
    float Value_NewValue(int v);
    float db_Value(int v);
    void  setTF(bool TF){setDisabled(TF);}
     //void paintEvent( QPaintEvent  *event);

signals:
    void valueChanged(float);
};


class Coordinate_system: public QWidget
{
    Q_OBJECT
private:
    QPixmap Pix;
public:
    Coordinate_system();
    //~Coordinate_system();
    void paintEvent( QPaintEvent  *);
    void set(float *input_x,float *input_y,int size);
public slots:;
    void refresh(){Pix.fill(Qt::black);update(); /*QPixmap new_pix=QPixmap();Pix=new_pix;*/};};

class control_meter: public QWidget
{
Q_OBJECT
 private:
  StereoVuMeter _vu;
  Coordinate_Fader _volume;
  QString _id;
  float _limit;
  Coordinate_system _cs;


  void paintEvent(QPaintEvent *);

 private slots:
  void volumeChanged(float);

 public:
     //按钮
     QPushButton *b0_31=new QPushButton;
     QPushButton *b32_63=new QPushButton;

     QPushButton *l0_31=new QPushButton;
     QPushButton *l32_63=new QPushButton;
     QPushButton *bset=new QPushButton;
     QPushButton *bgraph=new QPushButton;
     QPushButton *block=new QPushButton;
     QPushButton *bmute=new QPushButton;

     QLabel *data_label=new QLabel;
     QTextEdit *text_log=new QTextEdit;
     QLabel *volumeBox = new QLabel;
     QLabel *vuBox = new QLabel;


  control_meter(QString id, QString group="");
  ~control_meter();
  //void setvolumelabel(QString id) {_volume.setLabel(id);}
  void setLimit(float l) {_limit=l;}
  QString getID() {return _id;}
  void processBuffers(float *buf1, float *buf2, int size);
  void setvolume(int v=223){_volume.setValue(v);}
  void setvolumedb(int db){_volume.setValue(_volume.db_Value(db));}
  void setvurgb( int r=3,int y=10,int g=48,int b=70){_vu.setvurgb(r,y,g,b);}
  void setcf(bool TF){_volume.setTF(!TF);}
  void setvuboxtext(QString text){vuBox->setText(text);}
 public slots:
  void refresh() {_vu.refresh();_cs.refresh();}
  void SlotAppendText(QString text){text_log->append(text);}

};



#endif
