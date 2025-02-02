#include "mythread.h"

myThread::myThread(QObject *parent) : QObject(parent)
{
}
void myThread::alarm_process()
{

    //信号质量检测标准
    /**************左右声道反向**************/


    if(vm->getphaseValue()<=p){c++;}
    ptimes=ptimes+c_time;
    //相位系数
    if (c/size>=ps&&ptimes>pt){emit openalarm("声道反向");c=0;ptimes=0;};


    /**************低电平**************/


    if(vm->getLeftV()<=lv&&vm->getRightV()<=lv){lvc++;}
    ltimes=ltimes+c_time;
    //低电平系数
    if (lvc/size>=lvs&&ltimes>lvt){emit openalarm("低电平");c=0;ptimes=0;};


}
