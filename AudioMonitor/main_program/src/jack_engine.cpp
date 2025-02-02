
#include <math.h>
#include "jack_engine.h"

//JackEngine::JackEngine(): JackClient(), _master("master"),_cs("cs")
JackEngine::JackEngine(): JackClient(),_master("master")
{
  buffer1=NULL;
  buffer2=NULL;
  buffer3=NULL;
  buffer4=NULL;
}
JackEngine::~JackEngine()
{
  if (buffer1) {
    free(buffer1);
    free(buffer2);
  }
  if (buffer3) {
      free(buffer3);
      free(buffer4);
  }
}
bool JackEngine::initEngine(QString name)
{
  _audioProcessReady=false;
  if (initClient(name)) {
    if (buffer1) {
        free(buffer1);
        free(buffer2);
    }
    if (buffer3) {
        free(buffer3);
        free(buffer4);
    }
    buffer1=(jack_default_audio_sample_t*)malloc(sizeof(jack_default_audio_sample_t) * _blockSize);
    buffer2=(jack_default_audio_sample_t*)malloc(sizeof(jack_default_audio_sample_t) * _blockSize);
    buffer3=(jack_default_audio_sample_t*)malloc(sizeof(jack_default_audio_sample_t) * _blockSize);
    buffer4=(jack_default_audio_sample_t*)malloc(sizeof(jack_default_audio_sample_t) * _blockSize);
    addAudioOutput("master_1");
    addAudioOutput("master_2");
    _audioProcessReady=true;
    return true;
  }
  return false;
}

bool JackEngine::addMixer(VolumeMeter *vm)
{
  if (_client) {
    QString id=vm->getID();
    if (!addAudioInput(id + "_L") || !addAudioInput(id + "_R"))
      return false;
    connect(vm,SIGNAL(signalsID(QString)),this, SLOT(set_nowid(QString)));  //监听
    connect(vm,SIGNAL(signalsID(QString)),this, SLOT(set_flag_false(QString)));//停止轮听
    connect(vm,SIGNAL(left_signals_clicked(QString)),this, SLOT(left_button_fun(QString)));//设置
    //开启报警
    connect(vm,SIGNAL(singlesdata()),vm,SLOT(alarm_process()));
    connect(vm,SIGNAL(openalarm(QString)),&_master,SLOT(SlotAppendText(QString)));




  }

  //_mutex.lock();
  _mixers.append(vm);
  //_mutex.unlock();

  return true;
}
void JackEngine::removeMixer(VolumeMeter *vm)
{
  if (_client) {
    QString id=vm->getID();
    removeAudioInput(id + "_L");
    removeAudioInput(id + "_R");
  }
  //_mutex.lock();
  _mixers.removeAt(_mixers.indexOf(vm));
  //_mutex.unlock();
}
void JackEngine::refreshVu()
{
  if (_client) {
    for (int i=0; i < _mixers.count(); i++)
      _mixers.at(i)->refresh();
      _master.refresh();

  }
}
void JackEngine::master_process( jack_nframes_t nframes)
{


        //用于master输出
        jack_default_audio_sample_t *out1=(sample_t *)jack_port_get_buffer(_audioOutputs["master_1"], nframes);
        jack_default_audio_sample_t *out2=(sample_t *)jack_port_get_buffer(_audioOutputs["master_2"], nframes);
        //用于master输入
        jack_default_audio_sample_t *in1_now=(jack_default_audio_sample_t*)jack_port_get_buffer(_audioInputs[Now_id + "_L"], nframes);
        jack_default_audio_sample_t *in2_now=(jack_default_audio_sample_t *)jack_port_get_buffer(_audioInputs[Now_id + "_R"], nframes);
        memcpy(out1, in1_now, sizeof(jack_default_audio_sample_t) * nframes);
        memcpy(out2, in2_now, sizeof(jack_default_audio_sample_t) * nframes);
        _master.processBuffers(out1, out2, nframes);
        //用于master输出
        //qDebug()<<"now"<<Now_id<<nframes;
        //qDebug()<<"端口链接数"<<jack_port_connected(_audioInputs[Now_id + "_L"])	;
//        for (uint n=0; n < nframes; n++) {
//            out1[n]+=buffer3[n];
//            out2[n]+=buffer4[n];
//        }




}
void JackEngine::audio_process(jack_nframes_t nframes)
{
    //主线程
      if (!_audioProcessReady)
        return;

      check_process(nframes);

      if (_mixers.count() &&_audioOutputs["master_1"]) {
      _mutex.lock();
      master_process(nframes);
      _mutex.unlock();}



}
void JackEngine::set_nowid(int id_begin,int id_end){

    int count=id_begin;
    set_flag_true();
    while(flag){

        if(count<=id_end){
            if(flag==false){break;}
            QString now_id=QString::number(count);
            set_nowid(now_id);
            count++;}
        else{
            if(flag==false){break;}
            QString now_id=QString::number(id_begin);
            set_nowid(now_id);
            count=id_begin;}

        Sleep(Sleepmsec);
        qDebug()<<"flag:"<<flag<<count;
    }

}

void JackEngine::check_process( jack_nframes_t nframes){



    if (_mixers.count()) {
        for (int i=0; i < _mixers.count(); i++) {
            QString id=_mixers.at(i)->getID();
            _mixers.at(i)->set_bottom_name_label(_mixers.at(i)->getID());
            //无信号
            QString name_L=getName()+":"+id+"_L";
            QString name_R=getName()+":"+id+"_R";
            QList<QString> L_list=getConnections(name_L);
            QList<QString> R_list=getConnections(name_R);
            if(L_list.size()!=0 && R_list.size()!=0  ){
                sample_t *in1=(sample_t *)jack_port_get_buffer(_audioInputs[id + "_L"], nframes);
                sample_t *in2=(sample_t *)jack_port_get_buffer(_audioInputs[id + "_R"], nframes);
                memcpy(buffer1, in1, sizeof(jack_default_audio_sample_t) * nframes);
                memcpy(buffer2, in2, sizeof(jack_default_audio_sample_t) * nframes);
                _mixers.at(i)->processBuffers(in1, in2, nframes);
                connect(this,SIGNAL(sig_color(QString)), _mixers.at(i),SLOT(set_top_name_label_style(QString)));


              //检查buf是不是为空,
              if(in1[0]==in2[0] &&in1[0]==0){
                    emit sig_color("yellow");


                }else{emit sig_color("green");}




            }
            //未连接(关闭报警)
            if(L_list.size()==0 && R_list.size()==0  ){
              disconnect(this,SIGNAL(sig_color(QString)), _mixers.at(i),SLOT(set_top_name_label_style(QString)));
                    }
        }
    }

}



QStringList JackEngine::in_client(){
    QList<QString> list=getWritablePorts();
    QList<QString> res;
    QList<QString>::iterator i;
    for(i=list.begin(); i!=list.end(); ++i){
        QString new_i=*i->split(":").begin();
        if(res.indexOf(new_i)==-1){res << new_i;}//去重
    }
    return res;
}
QStringList  JackEngine::out_client(){
    QList<QString> list=getReadablePorts();
    QList<QString> res;
    QList<QString>::iterator i;
    for(i=list.begin(); i!=list.end(); ++i){
        QString new_i=*i->split(":").begin();
        if(res.indexOf(new_i)==-1){res << new_i;}//去重
    }

    return res;
}


void JackEngine::left_button_fun(QString id){
        QWidget w;
        QStringList allout=getReadablePorts();//ComboBox控件的内容
        bool ok1;
        bool ok2;
        QString textl=QInputDialog::getItem(&w, "该部件设置","左声道对象:", allout,0,false,&ok1);
        QString textr=QInputDialog::getItem(&w, "该部件设置","右声道对象:", allout,0,false,&ok2);
        if(ok1 &&ok2 && !textl.isEmpty()&& !textr.isEmpty()){
            QString vmr="rhdz:"+id+"_R";
            QString vml="rhdz:"+id+"_L";
            //关闭已连接通道
//            QString l=getConnections(vml)[0];
//            QString r=getConnections(vmr)[0];
//            qDebug()<<"链接通道"<<l<<r;
//            if(!l.isEmpty()){disconnectPorts(l,vml);}
//            if(!r.isEmpty()){disconnectPorts(r,vmr);}
            //链接声道
            connectPorts(textl,vml);
            connectPorts(textr,vmr);


        }



}
// jack_engine.cpp ends here
