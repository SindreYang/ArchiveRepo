

#ifndef VOLUME_METER_H
#define VOLUME_METER_H

#include "vumeter.h"
#include "midi_widgets.h"
class VolumeMeter : public QWidget
{
Q_OBJECT
 private:

  QString _id;
  float _limit;
  QLabel  *vu_right=new QLabel;
  QLabel  *vu_left=new QLabel;
  QLabel *Alarm_label=new QLabel;
  QLabel *bottom_name_label=new QLabel;
  QLineEdit *top_name_label=new QLineEdit;


  void paintEvent(QPaintEvent *);
  QPushButton *bottom_left_button=new QPushButton;
  QPushButton *bottom_right_button=new QPushButton;


  int size=1024;
  float p=-0.75;//阈值
  float pt=60.0;//持续时间
  float ps=0.6;//相关比例系数阈值
  int c=0;
  int c_time=1024/48000;//秒=样点/采样率
  int ptimes=0;//相位表计时器

  float lv=-48;
  float lvt=8;//持续时间
  float lvs=0.6;//相关比例系数阈值
  int lvc=0;
  int ltimes=0;//电平表计时器

 public:
  StereoVuMeter _vu;

  VolumeMeter(QString id, QString group="");
  ~VolumeMeter();
  void setLimit(float l) {_limit=l;}
  QString getID() {return _id;}
  void processBuffers(float *buf1, float *buf2, int size);
  double getphaseValue(){return _vu.getphaseValue();}
  float getLeftV(){return _vu.getLeftV();}
  float getRightV(){return _vu.getRightV();}
  void set_bottom_name_label(QString id){(bottom_name_label->setText(id));}

  void set_low_lv(float l){lv=l;}
  void set_bool_left_button(bool TF){bottom_left_button->setDisabled(TF);}
  void set_bool_right_button(bool TF){bottom_right_button->setDisabled(TF);}
  void setvurgb( int r,int y,int g,int b){_vu.setvurgb(r,y,g,b);}


 public slots:
     void set_top_name_label_style(QString style){(top_name_label->setStyleSheet("background-color:"+style));}
     void refresh() {_vu.refresh();}
     void start_alarm(QString info);
     void id_process();
     void left_bottom_process();
     void set_top_name_label(QString name){top_name_label->setText(name);}
     void alarm_process();//报警

Q_SIGNALS:

    void signalsID(QString id);
    void left_signals_clicked(QString id);
    void openalarm(QString info);//发送报警信号
    void singlesdata();


};

#endif

/* volume_meter.h ends here */
