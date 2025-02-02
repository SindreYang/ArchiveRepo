
#ifndef JACK_ENGINE_H
#define JACK_ENGINE_H

#include <QtGui>
#include <../C++/jack2_sever/jack_client.h>
#include <../C++/qt_module/volume_meter.h>
#include "mythread.h"
#include <../C++/qt_module/control_meter.h>
class JackEngine : public JackClient
{
Q_OBJECT

private:
  bool _audioProcessReady;
  jack_default_audio_sample_t *buffer1, *buffer2,*buffer3, *buffer4;
  QMutex _mutex;
  QString Now_id="0";
  bool flag=true;
  int Sleepmsec=1000;



  void audio_process(jack_nframes_t);


public:
  QList<VolumeMeter*> _mixers;
  control_meter _master;


  JackEngine();
  ~JackEngine();

  bool addMixer(VolumeMeter *vm);
  void removeMixer(VolumeMeter *vm);
  void master_process( jack_nframes_t);
  void check_process( jack_nframes_t);
  bool initEngine(QString name);
  void Sleep(int msec){QTime dieTime = QTime::currentTime().addMSecs(msec);while( QTime::currentTime() < dieTime )QCoreApplication::processEvents(QEventLoop::AllEvents, 100);}
  void set_msec(int msec){Sleepmsec=msec*1000;}
  int get_msec(){return Sleepmsec;}
  QStringList out_client();
  QStringList in_client();



public slots:
  void refreshVu();
  void set_nowid(QString id){Now_id=id;}
  void set_nowid(int id_begin,int id_end);
  void set_flag_false(QString id){flag=false;}
  void set_flag_true(){flag=true;}
  void left_button_fun(QString id);


Q_SIGNALS:
    void sig_name(QString name);
    void sig_color(QString color);

};



#endif
/* jack_engine.h ends here */
