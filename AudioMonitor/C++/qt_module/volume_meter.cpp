#include "volume_meter.h"

VolumeMeter::VolumeMeter(QString id, QString group)
{
  _id=id;
  _limit=-1;


  //电平表默认比例
  _vu.setvurgb(70,48,10,3);

  //设置类名
  vu_left->setObjectName("vu_left");
  vu_right->setObjectName("vu_right");
  Alarm_label->setObjectName("Alarm_label");
  bottom_name_label->setObjectName("bottom_name_label");
  top_name_label->setObjectName("top_name_label");
  bottom_left_button->setObjectName("bottom_left_button");
  bottom_right_button->setObjectName("bottom_right_button");
  //居中
  Alarm_label->setAlignment(Qt::AlignCenter);
  top_name_label->setAlignment(Qt::AlignCenter);
  bottom_name_label->setAlignment(Qt::AlignCenter);
  vu_left->setAlignment(Qt::AlignCenter);
  vu_right->setAlignment(Qt::AlignCenter);
  top_name_label->setAlignment(Qt::AlignCenter);
  top_name_label->setReadOnly(true);//只读
  //默认值
  Alarm_label->setText("Alarm");
  connect(&_vu, SIGNAL(LeftValue(int)),
      vu_left, SLOT(setNum(int)));
  connect(&_vu, SIGNAL(RightValue(int)),
          vu_right, SLOT(setNum(int)));
  connect(this, SIGNAL(openalarm(QString)),
          this, SLOT(start_alarm(QString)));

  connect(bottom_right_button,SIGNAL(clicked()),
          this, SLOT(id_process()));
  connect(bottom_left_button,SIGNAL(clicked()),
          this, SLOT(left_bottom_process()));


  //初始化最大高度
  vu_left->setMaximumHeight(20);
  vu_right->setMaximumHeight(20);
  Alarm_label->setMaximumHeight(20);
  bottom_name_label->setMaximumHeight(15);
  top_name_label->setMaximumHeight(15);
  bottom_left_button->setMaximumWidth(40);
  bottom_right_button->setMaximumWidth(40);


  //布局
  QHBoxLayout *bt=new QHBoxLayout;
  bt->addWidget(bottom_left_button);
  bt->addWidget(bottom_right_button);
  bt->setContentsMargins(0, 0, 0, 0);
  QHBoxLayout *p=new QHBoxLayout;
  p->addWidget(vu_left);
  p->addWidget(vu_right);
  p->setContentsMargins(0, 0, 0, 0);

  QVBoxLayout *vu=new QVBoxLayout;
  vu->addWidget(top_name_label);
  vu->addLayout(p);
  vu->addWidget(&_vu);
  vu->addWidget(Alarm_label);
  vu->addLayout(bt);
  vu->addWidget(bottom_name_label);
  vu->setSpacing(5);//上下边距
  vu->setSizeConstraint(QLayout::SetMaximumSize);
  setLayout(vu);


}
VolumeMeter:: ~VolumeMeter(){
     delete layout();

}
void VolumeMeter::paintEvent(QPaintEvent *)
{
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void VolumeMeter::start_alarm(QString info){
    Alarm_label->setStyleSheet("color:red;");
    Alarm_label->setText(info);

}


void VolumeMeter::id_process(){
     emit signalsID(bottom_name_label->text());

}
void VolumeMeter::left_bottom_process(){
     emit left_signals_clicked(bottom_name_label->text());
}

void VolumeMeter::alarm_process()
{

    //信号质量检测标准
    /**************左右声道反向**************/


    if(getphaseValue()<=p){c++;}
    ptimes=ptimes+c_time;
    //相位系数
    if (c/size>=ps&&ptimes>pt){emit openalarm("声道反向");c=0;ptimes=0;};


    /**************低电平**************/


    if(getLeftV()<=lv&&getRightV()<=lv){lvc++;}
    ltimes=ltimes+c_time;
    //低电平系数
    if (lvc/size>=lvs&&ltimes>lvt){emit openalarm("低电平");c=0;ptimes=0;};


}
void VolumeMeter::processBuffers(float *buf1, float *buf2, int size)
{
    emit singlesdata();
    _vu.processphaseValue(tau(buf1, buf2, size));
    _vu.processBuffers(buf1, buf2, size);
//   for (int i=0; i < size; i++) {
//        buf1[i]*=1.0;
//        buf2[i]*=1.0;
//        if (_limit != -1) {
//          buf1[i]=hard_clip(buf1[i], -_limit, _limit);
//          buf2[i]=hard_clip(buf2[i], -_limit, _limit);
//            }
        //buf1[i]=  0.1; //v:-20
        //buf1[i]=    0.0039810717055; //v:-48
        //buf2[i]=   0.31622776602; //v:-10
       //buf1[i]=  100; //v:越高界
        //buf2[i]= 5.6234132519e-4;//v:-65
//        _vu.processLeftValue(buf1[i]);
//        _vu.processRightValue(buf2[i]);

//    }
}



