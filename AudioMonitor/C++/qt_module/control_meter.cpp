#include "control_meter.h"


Coordinate_Fader::Coordinate_Fader()
{

    //setFixedHeight(300);
    setFixedWidth(30);

    int smin=0;
    int smax=300;
    QString stylesheet="QSlider::handle:vertical {image:url(:/myslider);width: 20px;height: 20px;margin:0 0 0 8;}";
    stylesheet+="QSlider::groove:vertical {border-image:url(:/mygroove);}";
    setStyleSheet(stylesheet);
    setRange(smin,smax);
    setSingleStep(1);
    setTickPosition(QSlider::TicksBothSides);//刻度在两侧


}

float Coordinate_Fader::Value_NewValue(int v){
    QMap<int,int>dict_v={
        {0, -70},
        {18, -60},
        {36, -40},
        {72, -30},
        {108, -20},
        {138, -15},
        {165, -10},
        {195, -5},
        {223, 0},
        {259, 6},
        {300, 12},};
    QMap<int,int>::iterator it;
    float new_value=0.0;
    float new_step=0.0;
    for(it = dict_v.begin(); it != dict_v.end(); it++) {
        if(it.key()<=v&&v<=(it+1).key()){
            new_step= float((it+1).key()-it.key())/float((it+1).value()-it.value());
            new_value=(v-it.key())/new_step+it.value();
            break;
        }
    }
    return new_value;
}
float Coordinate_Fader::db_Value(int v){
    QMap<int,int>dict_v={
        {0, -70},
        {18, -60},
        {36, -40},
        {72, -30},
        {108, -20},
        {138, -15},
        {165, -10},
        {195, -5},
        {223, 0},
        {259, 6},
        {300, 12},};
    QMap<int,int>::iterator it;
    float new_value=0.0;
    float new_step=0.0;
    for(it = dict_v.begin(); it != dict_v.end(); it++) {
        if(it.value()<=v&&v<=(it+1).value()){
            new_step= float((it+1).value()-it.value())/float((it+1).key()-it.key());
            new_value=(v-it.value())/new_step+it.key();
            break;
        }
    }
    return new_value;
}
float Coordinate_Fader::getParamValue()
{

    int v=value();
    //qDebug()<<"223-0"<<db_Value(0)<<"195-5"<<db_Value(-5);
    return Value_NewValue(v);

}




Coordinate_system::Coordinate_system(){
    setFixedSize(200, 200);
    //setMinimumSize(100, 100);
    Pix = QPixmap(height(), width());
    Pix.fill(Qt::black);

}

void Coordinate_system::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, height(),width(),Pix);
    painter.drawRect(0,0,width()-2,height()-2);
    painter.setPen(QPen(QColor(70,70,70),1,Qt::SolidLine));//虚线
    painter.drawText(8,18,"L");
    painter.drawText(width()-13,18,"R");
    painter.setWindow( -width()/2, height()/2,  width(), -height());
    painter.drawLine(-width()/2, 0, width()/2, 0);//x
    painter.drawLine(0, -height()/2, 0,height()/2   );//y
    painter.rotate(135);
    painter.drawLine(-width()/2, 0, width()/2, 0);
    painter.drawLine(0, -height()/2, 0,height()/2   );





//    if(Qu.size()<60){
//        if(getx()!=0 and gety()!=0 ){
//            QPointF xy=QPointF(getx()*100,gety()*100);
//            Qu<<xy;
//        }
//    }else{
//        foreach (QPointF var, Qu) {painter.drawPoint(var);}
//        /*painter.drawPolygon(Qu)*/;
//          Qu.removeFirst();
//    }
//    foreach (QPointF var, Qu) {
//        qDebug()<<"output"<<var<<endl;
//     }
 }
void Coordinate_system::set(float *x,float *y,int size){
    QPainter painter(&Pix);
    painter.setPen(QPen(QColor(	255,215,0), 3.3));

    int x_scale=width()/2;
    int y_scale=height()/2;
    painter.translate(x_scale,y_scale);
    painter.rotate(45);
    for (int i=0; i < size; i++) {
        QPointF xy=QPointF(x[i]*x_scale,y[i]*y_scale);
        painter.drawPoint(xy);
    }
    //printf("画点 %f \n",Pix.width());

    update();
}








control_meter::control_meter(QString id, QString group)
{
  _id=id;
  _limit=-1;
  //_volume.setMidiGroup(group);

    _volume.setValue(223);//音量表归零
    //connect(b13,&QPushButton::clicked,[=](){_volume.setValue(223);});
    //设置标题
    b0_31->setText("0-31");
    b32_63->setText("32-63");
    l0_31->setText("轮听1");
    l32_63->setText("轮听2");
    bset->setText("设置");
    bgraph->setText("报警");
    block->setText("锁定");
    bmute->setText("静音");

    //定时器
    QTimer *CurrentTime = new QTimer();
    CurrentTime->start(0);
    connect(CurrentTime,&QTimer::timeout,[=](){
        QDateTime current_time = QDateTime::currentDateTime();
        QString StrCurrentTime = current_time.toString("yyyy年MM月dd日 ddd hh:mm:ss ");


        data_label->setText(StrCurrentTime);
    });




    text_log->setText("                                  报警信息                     \n");
    //保持编辑器在光标最后一行
    QTextCursor cursor=text_log->textCursor();
    cursor.movePosition(QTextCursor::End);
    text_log->setTextCursor(cursor);


    //左边部分
    QGridLayout *glt = new QGridLayout();
    glt->addWidget(b0_31,0,0);
    glt->addWidget(b32_63,0,1);
    glt->addWidget(l0_31,1,0);
    glt->addWidget(l32_63,1,1);
    glt->addWidget(bset,2,0);
    glt->addWidget(bgraph,2,1);
    glt->addWidget(block,3,0);
    glt->addWidget(bmute,3,1);
    glt->addWidget(&_cs,4,0,2,2);


    //推子
    volumeBox->setObjectName("volumeBox");
    volumeBox->setFixedHeight(15);
    connect(&_volume, &QSlider::valueChanged, [=](int v){int new_v=_volume.Value_NewValue(v);volumeBox->setNum(new_v);});
    QVBoxLayout *volumelo=new QVBoxLayout;
    volumelo->addWidget(&_volume);
    volumelo->addWidget(volumeBox);
    //电平
    vuBox->setObjectName("vuBox");
    vuBox->setFixedHeight(15);
    vuBox->setText("轮听");
    QVBoxLayout *vulo=new QVBoxLayout;
    vulo->addWidget(&_vu);
    vulo->addWidget(vuBox);
    //右边部分(左右排列)
    QHBoxLayout *vu=new QHBoxLayout;
    vu->addLayout(glt);
    vu->addLayout(volumelo);
    vu->addLayout(vulo);
    vu->setMargin(0);


    //整体部分
    QVBoxLayout *lo=new QVBoxLayout;
    lo->addLayout(vu);
    lo->addWidget(data_label);
    lo->addWidget(text_log);

    setLayout(lo);
//  connect(&_volume, SIGNAL(valueChanged(float)),
//	  this, SLOT(volumeChanged(float)));
}
void control_meter::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QPainter painter(this);
}

void control_meter::volumeChanged(float val)
{
  //_volume.setLabel(QString("%1\n%2%").arg(_id).arg((int)(val * 100)));
  printf("%1.f",val);
}

void control_meter::processBuffers(float *buf1, float *buf2, int size)
{
    _vu.processphaseValue(tau(buf1, buf2, size));
    _cs.set(buf1,buf2,size);
    //_volume.setValue(0);//默认为0
    //_volume.setParamRange(dB_to_multiplier(-70.0),dB_to_multiplier(12.0));
    float volume=dB_to_multiplier(_volume.getParamValue());//将分贝转换成音量比

    //_volume.setLabel(QString::number(multiplier_to_dB(volume), 'f', 2));
    //qDebug()<<"音量:"<<volume<<"\n分贝:"<<multiplier_to_dB(volume);
    for (int i=0; i < size; i++) {
        buf1[i]*=volume;
        buf2[i]*=volume;
//        if (_limit != -1) {
//          buf1[i]=hard_clip(buf1[i], -_limit, _limit);
//          buf2[i]=hard_clip(buf2[i], -_limit, _limit);
//        }
        _vu.processLeftValue(buf1[i]);
        _vu.processRightValue(buf2[i]);

        //qDebug()<<"VU"<<_vu.getLeftV()<<_vu.getRightV();
  }
}

control_meter::~control_meter(){
    delete layout();
}
