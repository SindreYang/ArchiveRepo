

#include <QApplication>
////测试第一种vu表
//#include "../meter/qvumeter.h"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QVUMeter w;
//    for (double i=-70.0; i <30.0; i++){
//       w.setLeftValue(i);
//       w.show();
//    }
//    w.setRightValue(99);

//    return a.exec();
//}

////测试rhdz
//#include "../Integration/qv.h"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    qv *vm=new qv("");
//    vm->show();

//    return a.exec();
//}
//测试第2种vu表
#include "vumeter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Vu w1;
    StereoVuMeter w2;
    MeterStrip w3;
    //VuMeter w4;
    PhaseStrip t;
//    t.show();
//    w1.show();
     w2.show();
     w2.setvurgb(70,48,10,3);
//   w3.show();
    //w4.show();

    return a.exec();
}


//
//#include "control_meter.h"
//#include "vumeter.h"
//#include "volume_meter.h"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    control_meter *vm=new control_meter("");
//    vm->show();
////    Coordinate_system *cs=new Coordinate_system();
////    for(int i=0;i<1000;i++){
////        cs->setxy(10,i);
////    }
////    cs->show();
//    return a.exec();
//}



//#include "../algorithms_sever/audio_tools.h"

//using namespace std;
//int main()
//{
//    int w=0;
//    char c='A';
//    int v=100;
//    tay_lp(v,w,c);
//    qDebug()<<"output:"<<w<<c;
//    return  0;
//}
/*//测试第4种表
#include "../timebase_widget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeBaseWidget vm;
    //w.setPeak(float 20.0);
    vm.show();

    return a.exec();
}*/


////测试第5种下拉表
//#include "../presetbox.h"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    PresetBox vm;
//    //w.setPeak(float 20.0);
//    vm.show();

//    return a.exec();
//}


//测试第6种midi表
//#include "../qt_module/midi_widgets.h"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MidiInputBox vm1;
//    MidiOutputBox vm2;
//    MidiLearnerDlg vm3;
//    Midibut vm4;
//    Knob  vm5;
//    Fader vm6;
//    Midiknob vm7;
//    Midifader vm8;
//    MidiWidgetMap vm9;


////    vm1.show();
////    vm2.show();
////    vm3.show();
////    vm4.show();
////    vm5.show();
//    vm6.show();
////    vm7.show();
//    vm8.show();


//    return a.exec();
//}

////测试第7种开关
//#include "../metronom.h"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MetronomWidget vm;
//    //w.setPeak(float 20.0);
//    vm.show();

//    return a.exec();
//}



////测试rhdz
//#include "../../C++/qt_module/control_meter.h"
//    int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Coordinate_Fader vm;
//    vm.show();
//    vm.getParamValue();


//    return a.exec();
//}
