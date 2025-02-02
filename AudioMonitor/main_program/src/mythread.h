#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include "../C++/algorithms_sever/audio_tools.h"
#include <../C++/qt_module/volume_meter.h>
#include <../C++/qt_module/control_meter.h>
class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);
    VolumeMeter *vm;
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



public slots:
     void alarm_process();//报警


signals:
    void openalarm(QString info);//发送报警信号


};

#endif // MYTHREAD_H
