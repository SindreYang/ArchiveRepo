#include "qjackctlSetup.h"
#include <QApplication>
#include "qjackctlSetupForm.h"
#include "qjackctlMainForm.h"
class qjackctlSetup;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qjackctlSetup setup;
    qjackctlMainForm w(0, Qt::Window);
    w.setup(&setup);
    if (!setup.bSystemTray) {
        w.show();
        w.adjustSize();
//        w.showSetupForm();
//        w.toggleGraphForm();
        connect(ui->Graph, SIGNAL(clicked()),this,SLOT(w.toggleGraphForm()));
    }
    return a.exec();
}
