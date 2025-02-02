

#ifndef INJECTOR_H
#define INJECTOR_H
//#include "../C++/qjackctl/qjackctlSetupForm.h"
//#include "../C++/qjackctl/qjackctlMainForm.h"
#include <QtGui>
#include "jack_engine.h"
#include "ui_mainUI.h"
#include "ui_setup.h"
namespace Ui {
class rhdz;
}

class rhdz : public PanelItem
{
  Q_OBJECT
public:
    Ui::mainui *ui;
    Ui::setui *setui;
    QWidget wsetup;
    QString _clientName;
    QSettings settings;
    JackEngine _jack;
    QMap<QString,QString>  name_id;
    QMap<QString,QString>  id_pname;
    QMap<QString,QString>  titlelist;
    QString outl,outr;
    QVector<QString> tl1 ;
    QVector<QString> tl2 ;
//    qjackctlSetup setup;
//    qjackctlMainForm w;

    int _timerID;
    bool loadConf();
    bool saveConf();
    void config_setupui();
    void configUi();
    void setui_table_process();


private slots:
    void jackCtrlClicked();
    void jackStopped();
    void addAllMixerClicked();
//    void removeMixerClicked();
    void closeEvent(QCloseEvent*);

    void timerEvent(QTimerEvent *event);
    void changeIndex_0();
    void changeIndex_1();
    void changeIndex();
    void mute_process();
    void lock_process();
    void setupui();
    void check_setui_ok();
    void setl_outl_outr(QString l, QString r){outl=l;outr=r;}


public:
  explicit rhdz(QString clientName,QWidget *parent = 0);
  void Turns_Thread();
  ~rhdz();

signals:
    void sig_begin_end(int begin,int end);
};

#endif

