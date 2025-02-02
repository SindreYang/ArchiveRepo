
#include <QtXml>
#include <math.h>
#include "rhdz.h"
#include <QMessageBox>
#include <QThread>
#include <QTableWidgetItem>
rhdz::rhdz(QString clientName,QWidget *parent) :
    PanelItem(parent),
    ui(new Ui::mainui),
    setui(new Ui::setui)
{
    //读取配置路径
    _clientName="rhdz";
    //初始化界面
    ui->setupUi(this);
    //打开jack
    jackCtrlClicked();
    //加载所有vu表
    addAllMixerClicked();
    configUi();
    //载入配置
    //loadConf();
    mute_process();


}
rhdz::~rhdz()
{
    delete ui;
}
void rhdz::configUi(){
    //部件加载
    ui->tab1Layout->addWidget(&_jack._master);//加载监听组件
    ui->cpuMemorylabel->start(1000);//资源监测器开始运行
    //静音
    connect(_jack._master.bmute, SIGNAL(clicked()),
            this, SLOT(mute_process()));
    //锁定
    connect(_jack._master.block, SIGNAL(clicked()),
            this, SLOT(lock_process()));

    //界面切换
    connect(_jack._master.b0_31,SIGNAL(clicked()),this, SLOT(changeIndex_0()));
    connect(_jack._master.b32_63,SIGNAL(clicked()),this, SLOT(changeIndex_1()));
    //connect(ui->changeindex,SIGNAL(clicked()),this, SLOT(changeIndex()));
    //轮听线程
    Turns_Thread();
    //设置按钮
    connect(_jack._master.bset,SIGNAL(clicked()),this, SLOT(setupui()));
    config_setupui();
    //初始化jackctl
//    w.setup(&setup);
//    w.hide();
//    connect(_jack._master.bset,SIGNAL(clicked()),&w, SLOT(showSetupForm()));
//    connect(_jack._master.bgraph,SIGNAL(clicked()),&w, SLOT(toggleGraphForm()));

    connect(&_jack, SIGNAL(clientStopped()),
            this, SLOT(jackStopped()));


}

//界面切换
void rhdz::changeIndex_0(){ui->StackW->setCurrentIndex(0);}
void rhdz::changeIndex_1(){ui->StackW->setCurrentIndex(1);}
void rhdz::changeIndex(){
    int nCount = ui->StackW->count();
    int nIndex = ui->StackW->currentIndex();

    // 获取下一个需要显示的页面索引
    ++nIndex;

    // 当需要显示的页面索引大于等于总页面时，切换至首页
    if (nIndex >= nCount)
        nIndex = 0;

    ui->StackW->setCurrentIndex(nIndex);
}
bool rhdz::saveConf(){
        int y=setui->lineEdit_yellow->text().toInt();;
        int r=setui->lineEdit_red->text().toInt();
        int low=setui->lineEdit_low_lv->text().toInt();
        int db=setui->lineEdit_db->text().toInt();
        int confirmpp=setui->lineEdit_confirmp->text().toInt();
        int ltimes=setui->lineEdit_times->text().toInt();
        QString logopath=setui->lineEdit_logo->text();
        bool c1=setui->checkBox_1->isChecked();
        bool c2=setui->checkBox_1->isChecked();
        bool c3=setui->checkBox_1->isChecked();
        bool c4=setui->checkBox_1->isChecked();
        bool c5=setui->checkBox_1->isChecked();
        bool c6=setui->checkBox_1->isChecked();

        //参数节点
        settings.beginGroup("/params");
        settings.setValue("password", confirmpp);
        settings.setValue("y", y);
        settings.setValue("r", r);
        settings.setValue("low_lv", low);
        settings.setValue("db", db);
        settings.setValue("ltimes", ltimes);
        settings.setValue("logo", logopath);
        //settings.setValue("Checkbox1", c1);
        settings.setValue("Checkbox1", true);
        settings.setValue("Checkbox2", c2);
        settings.setValue("Checkbox3", c3);
        settings.setValue("Checkbox4", c4);
        settings.setValue("Checkbox5", c5);
        settings.setValue("Checkbox6", c6);
        settings.endGroup();


        settings.beginGroup("/title");
        QMap<QString, QString>::iterator ititle = titlelist.begin();
        while (ititle != titlelist.end()){
            settings.setValue(ititle.key(),ititle.value());
            ititle++;
        }
        settings.endGroup();


        //连接信息
        settings.beginGroup("/connections");
        QMap<QString, QString>::iterator iter = id_pname.begin();
        while (iter != id_pname.end()){
            settings.setValue("rhdz:"+iter.key(),iter.value());
            iter++;
        }
        settings.endGroup();
        qDebug()<<"连接配置保存成功";


        //名字对应id
        settings.beginGroup("/nameid");
        QMap<QString, QString>::iterator iter_name = name_id.begin();
        while (iter_name != name_id.end()){
            settings.setValue(iter_name.value(),iter_name.key());
            iter_name++;
        }
        settings.endGroup();
         qDebug()<<"名字对应id配置保存成功";


        //轮听信息
        settings.beginGroup("/l2");
        for(int i=1;i<setui->listWidget_tl2->count();i++)
        {
            settings.setValue(QString::number(i),setui->listWidget_tl2->item(i)->text());

        }
         settings.endGroup();

         settings.beginGroup("/l1");
        for(int i=1;i<setui->listWidget_tl1->count();i++)
        {
            settings.setValue(QString::number(i),setui->listWidget_tl1->item(i)->text());

        }

        settings.endGroup();

        settings.beginGroup("/l_now");
        for(int i=0;i<setui->listWidget_now->count();i++)
        {
            settings.setValue(QString::number(i),setui->listWidget_now->item(i)->text());

        }

        settings.endGroup();





        qDebug()<<"全部配置保存成功"<<settings.fileName();
        return true;

}
bool rhdz::loadConf(){

    return true;

}
void rhdz::jackCtrlClicked(){
    if (_jack.isActive()) {
        _jack.closeClient();
    }
    else {
        if (_jack.initEngine(_clientName)) {
            //ui->Start->setText(tr("停止"));
            int refresh=float(_jack.getBlockSize()) / _jack.getSamplerate() * 1000;
            qWarning() << "启动计时器，建议刷新时间为"<<refresh;
            _timerID=startTimer(refresh > 50 ? refresh : 50);
        }
        else
            QMessageBox::warning(this, tr("Error:"),tr("Jack 初始化失败!!!"));
    }

}
void rhdz::jackStopped() {
    //ui->Start->setText(tr("开始"));
    killTimer(_timerID);
}
void rhdz::closeEvent(QCloseEvent*)
{
    ui->cpuMemorylabel->stop();
    saveConf();
    killTimer(_timerID);
    _jack.closeClient();
}


void rhdz::addAllMixerClicked(){
    //int count=0;
    for (int cc = ui->Page1->layout()->count()-1; cc >= 0; --cc)
    {

        QLayoutItem *it = ui->Page1->layout()->itemAt(cc);
        QHBoxLayout *userlayout = qobject_cast<QHBoxLayout *>(it->layout());

        if (userlayout != 0)
        {
            userlayout->addStretch();
            QString ln=userlayout->objectName();
            int l_int_begin=ln.split("_")[1].toInt();
            int b=(l_int_begin-1)*4;
            int e=l_int_begin*4;
            for(int i=b;i<e;i++){
                QString name=QString("%1").arg(i);
                VolumeMeter *vm=new VolumeMeter(name);
                if (!_jack.addMixer(vm)) {
                    delete vm;
                    return;
                }
                userlayout->addWidget(vm);
                //count++;
                userlayout->setSpacing(0);
                userlayout->setMargin(0);
            }


        }
    }

    for (int cc = ui->page2->layout()->count()-1; cc >= 0; --cc)
    {

        QLayoutItem *it = ui->page2->layout()->itemAt(cc);
        QHBoxLayout *userlayout = qobject_cast<QHBoxLayout *>(it->layout());
        if (userlayout != 0)
        {
            userlayout->addStretch();
            QString ln=userlayout->objectName();
            int l_int_begin=ln.split("_")[1].toInt();
            int b=(l_int_begin-1)*4;
            int e=l_int_begin*4;
            for(int i=b;i<e;i++){
                QString name=QString("%1").arg(i);
                VolumeMeter *vm=new VolumeMeter(name);
                if (!_jack.addMixer(vm)) {
                    delete vm;
                    return;
                }
                userlayout->addWidget(vm);
                //count++;
                userlayout->setSpacing(0);
                userlayout->setMargin(0);
            }

        }
    }

}
void rhdz::timerEvent(QTimerEvent *event) {
    if (event->timerId() == _timerID) {
        _jack.refreshVu();
    }
    QWidget::timerEvent(event);
}

void rhdz::Turns_Thread(){
    connect(ui->pushButton_1,&QPushButton::clicked,[=](){_jack.set_nowid(0,3);});//发信号
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){_jack.set_nowid(4,7);});//发信号
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){_jack.set_nowid(8,11);});//发信号
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){_jack.set_nowid(12,15);});//发信号
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){_jack.set_nowid(16,19);});//发信号
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){_jack.set_nowid(20,23);});//发信号
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){_jack.set_nowid(24,27);});//发信号
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){_jack.set_nowid(28,31);});//发信号

    connect(ui->pushButton_9,&QPushButton::clicked,[=](){_jack.set_nowid(32,35);});//发信号
    connect(ui->pushButton_10,&QPushButton::clicked,[=](){_jack.set_nowid(36,39);});//发信号
    connect(ui->pushButton_11,&QPushButton::clicked,[=](){_jack.set_nowid(40,43);});//发信号
    connect(ui->pushButton_12,&QPushButton::clicked,[=](){_jack.set_nowid(44,47);});//发信号
    connect(ui->pushButton_13,&QPushButton::clicked,[=](){_jack.set_nowid(48,51);});//发信号
    connect(ui->pushButton_14,&QPushButton::clicked,[=](){_jack.set_nowid(52,55);});//发信号
    connect(ui->pushButton_15,&QPushButton::clicked,[=](){_jack.set_nowid(56,59);});//发信号
    connect(ui->pushButton_16,&QPushButton::clicked,[=](){_jack.set_nowid(60,63);});//发信号




}
void rhdz::mute_process(){
    if(outl!=NULL&&outl!=NULL){
        if(_jack._master.bmute->text()=="静音"){
            bool c1=_jack.connectPorts("rhdz:master_1",outl);
            bool c2=_jack.connectPorts("rhdz:master_2",outr);
            if(c1&&c2){_jack._master.bmute->setText("播放");}else{_jack._master.bmute->setText("静音");}}
        else{
           bool c1=_jack.disconnectPorts("rhdz:master_1",outl);
           bool c2=_jack.disconnectPorts("rhdz:master_2",outr);
           if(c1&&c2){_jack._master.bmute->setText("静音");}else{_jack._master.bmute->setText("播放");}
           }
    }



}
void rhdz::lock_process(){
    if(_jack._master.block->text()=="锁定"){
        _jack._master.b0_31->setEnabled(false);
        _jack._master.b32_63->setEnabled(false);
        _jack._master.l0_31->setEnabled(false);
        _jack._master.l32_63->setEnabled(false);
        _jack._master.bgraph->setEnabled(false);
        _jack._master.bmute->setEnabled(false);
        _jack._master.bset->setEnabled(false);
        _jack._master.block->setText("解锁");
        }
    else{
        _jack._master.b0_31->setEnabled(true);
        _jack._master.b32_63->setEnabled(true);
        _jack._master.l0_31->setEnabled(true);
        _jack._master.l32_63->setEnabled(true);
        _jack._master.bgraph->setEnabled(true);
        _jack._master.bmute->setEnabled(true);
        _jack._master.bset->setEnabled(true);
        _jack._master.block->setText("锁定");
    }




}

void rhdz::setupui(){

          wsetup.show();


}

void rhdz::config_setupui(){
      setui->setupUi(&wsetup);


     /************************设置界面**********************/

     //打开log图片
//     connect(setui->openfile,&QPushButton::clicked,[=](){QString fileName = QFileDialog::getOpenFileName(NULL);
//        setui->lineEdit_logo->setText(fileName);});
     //界面切换
      /*单选菜单效果*/
      QButtonGroup *buttonGround = new QButtonGroup();
      buttonGround->addButton(setui->pushButton_1);
      buttonGround->addButton(setui->pushButton_2);
      buttonGround->addButton(setui->pushButton_3);
      buttonGround->setExclusive(true);
     connect(setui->pushButton_1,&QPushButton::clicked,[=](){setui->stackedWidget->setCurrentIndex(0);});
     connect(setui->pushButton_2,&QPushButton::clicked,[=](){setui->stackedWidget->setCurrentIndex(1);});
     connect(setui->pushButton_3,&QPushButton::clicked,[=](){setui->stackedWidget->setCurrentIndex(2);});

     //取消
     connect(setui->pushButton_Cancel,&QPushButton::clicked,[=](){wsetup.close();});
     //ok
     connect(setui->pushButton_ok,SIGNAL(clicked()),this,SLOT(check_setui_ok()));
     //参数
     setui->lineEdit_red->setValidator(new QIntValidator(-3,-20));
     setui->lineEdit_red->setValidator(new QIntValidator(-10,-3));
     setui->lineEdit_low_lv->setValidator(new QIntValidator(-50,-30));
     setui->lineEdit_db->setValidator(new QIntValidator(-30,0));
     setui->lineEdit_times->setValidator(new QIntValidator(10,100));

     settings.beginGroup("/params");
     setui->lineEdit_yellow->setText(settings.value("y").toString());
     setui->lineEdit_red->setText(settings.value("r").toString());
     setui->lineEdit_low_lv->setText(settings.value("low_lv").toString());
     setui->lineEdit_db->setText(settings.value("db").toString());
     //密码
     setui->lineEdit_initp->setEchoMode(QLineEdit::PasswordEchoOnEdit );
     setui->lineEdit_initp->setText(settings.value("password").toString());
     setui->lineEdit_changep->setText(settings.value("password").toString());
     setui->lineEdit_confirmp->setText(settings.value("password").toString());
     //间隔
     setui->lineEdit_times->setText(settings.value("ltimes").toString());
     setui->lineEdit_logo->setText(settings.value("logo").toString());

     //锁定
     setui->checkBox_1->setChecked(settings.value("Checkbox1").toBool());
     setui->checkBox_2->setChecked(settings.value("Checkbox2").toBool());
     setui->checkBox_3->setChecked(settings.value("Checkbox3").toBool());
     setui->checkBox_4->setChecked(settings.value("Checkbox4").toBool());
     setui->checkBox_5->setChecked(settings.value("Checkbox5").toBool());
     setui->checkBox_6->setChecked(settings.value("Checkbox6").toBool());


     settings.endGroup();





     //通道管理
     //自适应文字
     setui->tableWidget_lr->verticalHeader()->setDefaultSectionSize(60);
     setui->tableWidget_lr->resizeColumnsToContents();
     //setui->tableWidget_lr->resizeRowsToContents();



     //按钮标题(每个合并4行)初始
     for(int i=0;i<64;i=i+4){
         setui->tableWidget_lr->setSpan(i, 1, 4, 1);//其参数为： 要改变单元格的 行数 列数 要合并的 行数 列数
         setui->tableWidget_lr->setItem(i,1,new QTableWidgetItem("title_"+QString::number(i)));;
     }

     //表头(不可编辑)初始
     for(int i=0;i<64;i++){
         QTableWidgetItem *item = new QTableWidgetItem(QString::number(i));

         item->setFlags(item->flags() & (~Qt::ItemIsEditable));

         item->setFlags(Qt::NoItemFlags);
         setui->tableWidget_lr->setItem(i,0,item);
         setui->tableWidget_lr->setItem(i,2,new QTableWidgetItem("逻辑_"+QString::number(i)));
         QListWidget *cl=new QListWidget;
         cl->setAcceptDrops(true);
         setui->tableWidget_lr->setCellWidget(i,3,cl);
//         //如果大于2,就放到表3
//         connect(cl,&QListWidget::itemSelectionChanged,[=](){if(cl->count()>1){
//                setui->tableWidget_lr->setItem(i,2,new QTableWidgetItem(cl->item(0)->text()+","+cl->item(1)->text()));
//                setui->tableWidget_lr->removeCellWidget(i,2);

//            }});


         //右键删除
         cl->setContextMenuPolicy(Qt::CustomContextMenu); // 设置鼠标右键
         /*初始化一个包含两个Action(Delete和ClearAll)的菜单*/
         QMenu *popMenu_In_ListWidget_= new QMenu(this);;/*弹出菜单*/
         QAction *action_Delete_In_ListWidget_= new QAction(tr("删除"), this);;/*菜单上的Action*/
         popMenu_In_ListWidget_->addAction(action_Delete_In_ListWidget_);
         /*为菜单上的Delete选项添加响应函数*/
         connect(action_Delete_In_ListWidget_, &QAction::triggered, [=](){              /*获取当前选中的Item*/
                                                                            QList<QListWidgetItem*> items = cl->selectedItems();


                                                                            if (items.count() > 0)
                                                                            {
                                                                                /*弹出询问对话框*/
                                                                                if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("删除这个通道"),
                                                                                                                              QStringLiteral("删除 %1 行").arg(QString::number(items.count())), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
                                                                                {
                                                                                    foreach(QListWidgetItem* var, items) {
                                                                                        cl->removeItemWidget(var);
                                                                                        items.removeOne(var);
                                                                                        delete var;
                                                                                    }
                                                                                }
                                                                            }});
         connect(cl, &QWidget::customContextMenuRequested,[=](const QPoint &){
                    popMenu_In_ListWidget_->exec(QCursor::pos());});

    }


    setui->listWidget_pc->setDragEnabled(true);
    //可以选择多个item
    setui->listWidget_pc->setSelectionMode(QAbstractItemView::ExtendedSelection);


    //监听设备
    setui->comboBox_outp->addItems(_jack.in_client());
    //监听通道列表
    connect(setui->comboBox_outp,&QComboBox::currentTextChanged,[=](const QString & text){
        setui->listWidget_pc_2->clear();//清空原有的列表
        QStringList allout=_jack.getWritablePorts();
        QList<QString>::iterator i;
        for(i=allout.begin(); i!=allout.end(); ++i){
            QString new_i=*i->split(":").begin();
            if(new_i==text){ setui->listWidget_pc_2->addItem(*i);}
        }
    });

    //正在监听列表右键删除
    setui->listWidget_now->setContextMenuPolicy(Qt::CustomContextMenu);
    setui->listWidget_now->setDefaultDropAction(Qt::MoveAction);
    setui->listWidget_now->setDragEnabled(true);
    QMenu *popMenu_listWidget_now= new QMenu(this);;
    QAction *action_listWidget_now= new QAction(tr("清空"), this);
    popMenu_listWidget_now->addAction(action_listWidget_now);
    connect(action_listWidget_now, &QAction::triggered, [=](){ setui->listWidget_now->clear(); });
    connect(setui->listWidget_now, &QWidget::customContextMenuRequested,[=](const QPoint &){popMenu_listWidget_now->exec(QCursor::pos());});





    //输入设备
    setui->comboBox_inputp->addItems(_jack.out_client());
    //物理通道列表

    // QString now_comboBox_name=setui->comboBox_inputp->currentText();
    connect(setui->comboBox_inputp,&QComboBox::currentTextChanged,[=](const QString & text){
                                setui->listWidget_pc->clear();//清空原有的列表
                                QStringList allout=_jack.getReadablePorts();
                                QList<QString>::iterator i;
                                for(i=allout.begin(); i!=allout.end(); ++i){
                                    QString new_i=*i->split(":").begin();
                                    if(new_i==text){ setui->listWidget_pc->addItem(*i);}
                                }
    });

     //轮听
     setui->listWidget_lc->setDragEnabled(true);
     setui->listWidget_tl2->setAcceptDrops(true);
     setui->listWidget_tl1->setAcceptDrops(true);


     //可以选择多个item
     setui->listWidget_lc->setSelectionMode(QAbstractItemView::ExtendedSelection);
     //右键删除
     setui->listWidget_tl1->setContextMenuPolicy(Qt::CustomContextMenu); // 设置鼠标右键
     setui->listWidget_tl2->setContextMenuPolicy(Qt::CustomContextMenu); // 设置鼠标右键
     /*初始化一个包含两个Action(Delete)的菜单*/
     QMenu *popMenu_In_ListWidget_1= new QMenu(this);;/*弹出菜单*/
     QAction *action_Delete_In_ListWidget_1= new QAction(tr("删除"), this);;/*菜单上的Action*/
     popMenu_In_ListWidget_1->addAction(action_Delete_In_ListWidget_1);

     QMenu *popMenu_In_ListWidget_2= new QMenu(this);;/*弹出菜单*/
     QAction *action_Delete_In_ListWidget_2= new QAction(tr("删除"), this);;/*菜单上的Action*/
     popMenu_In_ListWidget_2->addAction(action_Delete_In_ListWidget_2);
     /*为菜单上的Delete选项添加响应函数*/
     connect(action_Delete_In_ListWidget_1, &QAction::triggered, [=](){              /*获取当前选中的Item*/
                                                                        QList<QListWidgetItem*> items = setui->listWidget_tl1->selectedItems();


                                                                        if (items.count() > 0)
                                                                        {
                                                                            /*弹出询问对话框*/
                                                                            if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("删除这个通道"),
                                                                                                                          QStringLiteral("删除 %1 行").arg(QString::number(items.count())), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
                                                                            {
                                                                                foreach(QListWidgetItem* var, items) {
                                                                                    setui->listWidget_tl1->removeItemWidget(var);
                                                                                    items.removeOne(var);
                                                                                    delete var;
                                                                                }
                                                                            }
                                                                        }});
     connect(action_Delete_In_ListWidget_2, &QAction::triggered, [=](){              /*获取当前选中的Item*/
                                                                         QList<QListWidgetItem*> items = setui->listWidget_tl2->selectedItems();


                                                                         if (items.count() > 0)
                                                                         {
                                                                             /*弹出询问对话框*/
                                                                             if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("删除这个通道"),
                                                                                                                           QStringLiteral("删除 %1 行").arg(QString::number(items.count())), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
                                                                             {
                                                                                 foreach(QListWidgetItem* var, items) {
                                                                                     setui->listWidget_tl2->removeItemWidget(var);
                                                                                     items.removeOne(var);
                                                                                     delete var;
                                                                                 }
                                                                             }
                                                                         }});

     connect(setui->listWidget_tl2, &QWidget::customContextMenuRequested,[=](const QPoint &){
         popMenu_In_ListWidget_2->exec(QCursor::pos());});
     connect(setui->listWidget_tl1, &QWidget::customContextMenuRequested,[=](const QPoint &){
         popMenu_In_ListWidget_1->exec(QCursor::pos());});
     for(int i=0;i<setui->tableWidget_lr->rowCount();i++)
     {
         setui->listWidget_lc->addItem( setui->tableWidget_lr->item(i,2)->text());

     }







     //通过配置加载table,l1,l2

     settings.beginGroup("/title");
     QStringList keys_title = settings.allKeys();
     for (int i = 0; i < keys_title.count(); ++i)
     {
         QString key = keys_title[i];
         int k=key.toInt();
         QString value = settings.value(key).toString();
         setui->tableWidget_lr->setItem(k,1,new QTableWidgetItem(value));

     }
     settings.endGroup();

     settings.beginGroup("/connections");
     QStringList keys = settings.allKeys();
     for (int i = 0; i < keys.count(); i=i+2)
     {

         QString key = keys[i];
         QString value = settings.value(key).toString();
         QString key2 = keys[i+1];
         QString value2 = settings.value(key2).toString();
         //转换成对应行
         QString idtmp=key.split(":")[1];
         QString idtmp2=idtmp.split("_")[0];
         int id=idtmp2.toInt();



         //qDebug()<<key<<key2;
         QStringList sumv;
         QListWidget *cl1=new QListWidget;
         cl1->setAcceptDrops(true);
         //右键删除
         cl1->setContextMenuPolicy(Qt::CustomContextMenu); // 设置鼠标右键
         /*初始化一个包含两个Action(Delete和ClearAll)的菜单*/
         QMenu *popMenu_In_ListWidget_= new QMenu(this);;/*弹出菜单*/
         QAction *action_Delete_In_ListWidget_= new QAction(tr("删除"), this);;/*菜单上的Action*/
         popMenu_In_ListWidget_->addAction(action_Delete_In_ListWidget_);
         /*为菜单上的Delete选项添加响应函数*/
         connect(action_Delete_In_ListWidget_, &QAction::triggered, [=](){              /*获取当前选中的Item*/
                                                                            QList<QListWidgetItem*> items = cl1->selectedItems();


                                                                            if (items.count() > 0)
                                                                            {
                                                                                /*弹出询问对话框*/
                                                                                if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("删除这个通道"),
                                                                                                                              QStringLiteral("删除 %1 行").arg(QString::number(items.count())), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
                                                                                {
                                                                                    foreach(QListWidgetItem* var, items) {
                                                                                        cl1->removeItemWidget(var);
                                                                                        items.removeOne(var);
                                                                                        delete var;
                                                                                    }
                                                                                }
                                                                            }});
         connect(cl1, &QWidget::customContextMenuRequested,[=](const QPoint &){
             popMenu_In_ListWidget_->exec(QCursor::pos());});

         sumv<<value<<value2;
         cl1->addItems(sumv);
         setui->tableWidget_lr->setCellWidget(id,3,cl1);



     }
     settings.endGroup();
     //名字对应id
     settings.beginGroup("/nameid");
     QStringList keys_nameid = settings.allKeys();
     for (int i = 0; i < keys_nameid.count(); ++i)
     {
         QString key = keys_nameid[i];
         int k=key.toInt();
         QString value = settings.value(key).toString();
         setui->tableWidget_lr->setItem(k,2,new QTableWidgetItem(value));

     }
     //加载轮听列表
     setui->listWidget_lc->clear();
     for(int i=0;i<setui->tableWidget_lr->rowCount();i++)
     {
         setui->listWidget_lc->addItem( setui->tableWidget_lr->item(i,2)->text());

     }
     settings.endGroup();
     //轮听
     settings.beginGroup("/l1");
     QStringList l1settings;
     QStringList keys_l1 = settings.allKeys();
     for (int i = 0; i < keys_l1.count(); ++i)
     {
         QString key = keys_l1[i];
         QString value = settings.value(key).toString();
         l1settings<<value;

     }
     setui->listWidget_tl1->addItems(l1settings);
     settings.endGroup();
     settings.beginGroup("/l2");
     QStringList l2settings;
     QStringList keys_l2 = settings.allKeys();
     for (int i = 0; i < keys_l2.count(); ++i)
     {
         QString key = keys_l2[i];
         QString value = settings.value(key).toString();
         l2settings<<value;

     }
     setui->listWidget_tl2->addItems(l2settings);
     settings.endGroup();

      //监听
     settings.beginGroup("/l_now");
     QStringList lr;
     lr<<settings.value("0").toString()<<settings.value("1").toString();
     setui->listWidget_now->addItems(lr);
     settings.endGroup();




}
void rhdz::check_setui_ok(){
    int y=setui->lineEdit_yellow->text().toInt();;
    int r=setui->lineEdit_red->text().toInt();
    int low=setui->lineEdit_low_lv->text().toInt();
    int db=setui->lineEdit_db->text().toInt();
    QString initp=setui->lineEdit_initp->text();
    int changep=setui->lineEdit_changep->text().toInt();
    int confirmpp=setui->lineEdit_confirmp->text().toInt();
    int ltimes=setui->lineEdit_times->text().toInt();
    bool c1=setui->checkBox_1->isChecked();
    bool c2=setui->checkBox_1->isChecked();
    bool c3=setui->checkBox_1->isChecked();
    bool c4=setui->checkBox_1->isChecked();
    bool c5=setui->checkBox_1->isChecked();
    bool c6=setui->checkBox_1->isChecked();
    //判断确认密码是否相同
    if(changep!=confirmpp){QMessageBox::critical(0 ,"密码管理" , "修改密码与确认密码不匹配",QMessageBox::Ok | QMessageBox::Default ); }
    //判断范围是否符合
    else if(!(-20<=y&&y<=-3)){QMessageBox::critical(0 ,"参数设置" , "表头黄线范围错误",QMessageBox::Ok | QMessageBox::Default ); }
    else if(!(-10<=r&&r<=0)){QMessageBox::critical(0 ,"参数设置" , "表头红线范围错误",QMessageBox::Ok | QMessageBox::Default ); }
    else if(!(-50<=low&&low<=-30)){QMessageBox::critical(0 ,"参数设置" , "低电平范围错误",QMessageBox::Ok | QMessageBox::Default ); }
    else if(!(-30<=db&&db<=0)){QMessageBox::critical(0 ,"参数设置" , "监听增益范围错误",QMessageBox::Ok | QMessageBox::Default ); }
    else if(!(10<=ltimes&&ltimes<=100)){QMessageBox::critical(0 ,"参数设置" , "间隔时间错误",QMessageBox::Ok | QMessageBox::Default ); }
    else if(r<=y){QMessageBox::critical(0 ,"参数设置" , "红色先应该大于黄色线",QMessageBox::Ok | QMessageBox::Default ); }
    else if(initp!=settings.value("/params/password").toString()){QMessageBox::critical(0 ,"初始密码错误" , "初始密码错误",QMessageBox::Ok | QMessageBox::Default ); }



    //都符合
    //修改对应参数
    else{
        _jack._master.setvolumedb(db);
        _jack._master.setvurgb(70,48,qAbs(y),qAbs(r));
        _jack.set_msec(ltimes);
        setui_table_process();
        //锁定
        //设置右键是否开启
        for (int i=0; i < _jack._mixers.count(); i++) {_jack._mixers.at(i)->setvurgb(70,48,qAbs(y),qAbs(r));_jack._mixers.at(i)->set_bool_left_button(true);_jack._mixers.at(i)->set_bool_right_button( c2);}
        _jack._master.l0_31->setDisabled(c2);
        _jack._master.l32_63->setDisabled(c2);
        _jack._master.bset->setDisabled(c3);
        _jack._master.bgraph->setDisabled(c4);
        _jack._master.bmute->setDisabled(c5);
        _jack._master.setcf(c6);
        QImage *img=new QImage;
        img->load(setui->lineEdit_logo->text());
        ui->ACElabel->setPixmap(QPixmap::fromImage(*img));

        QMessageBox::critical(0 ,"设置成功" , "参数设置成功",QMessageBox::Ok | QMessageBox::Default );

    }







}

void rhdz::setui_table_process(){

    QString tableID;
    QString tablename;





    //遍历table
    //按钮标题(每个合并4行)
    for(int i=0;i<64;i=i+4){
        setui->tableWidget_lr->setSpan(i, 1, 4, 1);
        QString tmp = setui->tableWidget_lr->item(i,1)->text();
        titlelist.insert(QString::number(i), tmp);

        int pb_id=i/4+1;
        QPushButton* pb=findChild<QPushButton*>("pushButton_"+QString::number(pb_id));
        if(pb!=NULL){pb->setText(tmp);}

    }
    for(int i=0; i<setui->tableWidget_lr->rowCount(); i++){ // 取出每个格子的内容
        if(setui->tableWidget_lr->item(i,0) != NULL && setui->tableWidget_lr->item(i,2) != NULL){
            tableID = setui->tableWidget_lr->item(i,0)->text();
            tablename = setui->tableWidget_lr->item(i,2)->text();
            name_id.insert(tablename,tableID);

            QListWidget *tablelistwidget = (QListWidget *)setui->tableWidget_lr->cellWidget(i,3);
            if(tablelistwidget->item(0)!=NULL && tablelistwidget->item(1)!=NULL){
                QString ltext=tablelistwidget->item(0)->text();
                QString rtext=tablelistwidget->item(1)->text();
                if(ltext.indexOf("_L")!=-1 || ltext.indexOf("_1")!=-1){id_pname.insert(tableID+"_L",ltext);id_pname.insert(tableID+"_R",rtext);}
                else{id_pname.insert(tableID+"_L",ltext);id_pname.insert(tableID+"_R",ltext);}
            }
        }
    }
    //链接物理通道
    QMap<QString, QString>::iterator iter = id_pname.begin();
    while (iter != id_pname.end()){qDebug() << "链接物理通道 " << iter.key() << ":" << iter.value();_jack.connectPorts(iter.value(),"rhdz:"+iter.key()); iter++;}


    //设置轮听

    for (int j = 0; j < setui->listWidget_tl1 ->count(); j++){
        QString name=setui->listWidget_tl1->item(j)->text();
        QString id=name_id.value(name);
        tl1.append(id);

    }
    for (int j = 0; j < setui->listWidget_tl2 ->count(); j++){
        QString name=setui->listWidget_tl2->item(j)->text();
        QString id=name_id.value(name);
        tl2.append(id);
    }

    connect(_jack._master.l0_31,&QPushButton::clicked,[=](){ if(tl1.size()!=0) {foreach (QString id, tl1) {
            qDebug()<<"轮听"<<id;
        _jack.set_nowid(id);
        _jack.Sleep(_jack.get_msec());
    }}});

    connect(_jack._master.l32_63,&QPushButton::clicked,[=](){if(tl2.size()!=0) {foreach (QString id, tl2) {
             qDebug()<<"轮听"<<id;
        _jack.set_nowid(id);
        _jack.Sleep(_jack.get_msec());
    }}});


    //设置顶部标签
    if (_jack._mixers.count()) {
        for (int i=0; i < _jack._mixers.count(); i++) {
            QString id=_jack._mixers.at(i)->getID();
            QString ln=name_id.key(id);
            _jack._mixers.at(i)->set_top_name_label(ln);
        }
    }

    //监听

    QString l=setui->listWidget_now ->item(0)->text();
    QString r=setui->listWidget_now ->item(1)->text();
    setl_outl_outr(l,r);

}
