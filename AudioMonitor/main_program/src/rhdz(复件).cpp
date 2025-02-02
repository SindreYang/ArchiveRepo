

#include <QtXml>
#include <math.h>
#include "rhdz.h"


//Injector::Injector(QString clientName ) : _midiLearner(this)
Injector::Injector(QString clientName,QWidget *parent):
    QMainWindow::PanelItem(parent),ui(new Ui::mainwindow)
{
  _menu=NULL;
  if (!clientName.isEmpty()) {
    _clientName=clientName;
    _confFile=QDir::homePath()+"/.rhdz."+_clientName;
  }
  else {
    _clientName="rhdz";
    _confFile=QDir::homePath()+"/.rhdz";
  }
  //setUpGui();
  ui->setupUi(this);

  __midiWidgetMap.setMidiLearner(&_midiLearner);

  jackCtrlClicked();

  loadConf();
}

Injector::~Injector(){
}

void Injector::closeEvent(QCloseEvent*)
{
  //_vuTimer.stop();
  saveConf();
  _jack.closeClient();
  //qDebug()<<"closing";
}
void Injector::setUpGui() {
 if (_trayIcon.isSystemTrayAvailable()) {
   _trayIcon.setIcon(QIcon(QPixmap(":/logo")));
   _trayIcon.setToolTip(QString("[%1] rhdz").arg(_clientName));
   _trayIcon.show();
 }
 _jackGB.setTitle(tr("Jack client"));
 mainui.toolLayout->addWidget(&_jackClientActivation);
 _jackGB.setLayout(mainui.toolLayout);

 _staxaudio.setPixmap(QPixmap(":/staxaudio"));
 QHBoxLayout *menubar=new QHBoxLayout;
 menubar->addWidget(&_staxaudio);
 menubar->addStretch();
 menubar->addWidget(&_midiIn);
 menubar->addWidget(&_jackGB);

 _addMixer.setIcon(QIcon(QPixmap(":/add")));
 _removeMixer.setIcon(QIcon(QPixmap(":/remove")));
 QHBoxLayout *act=new QHBoxLayout;
 act->addWidget(&_addMixer);
 act->addWidget(&_removeMixer);
 act->addStretch();

 _mixerGrid.setSelectionMode(QAbstractItemView::NoSelection);
 _mixerGrid.setRowCount(1);
 _mixerGrid.setColumnCount(0);
 _mixerGrid.horizontalHeader()->setDefaultSectionSize(120);
 _mixerGrid.verticalHeader()->setDefaultSectionSize(300);
 //_mixerGrid.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
 _mixerGrid.horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
 _mixerGrid.verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
 _mixerGrid.horizontalHeader()->hide();
 _mixerGrid.verticalHeader()->hide();
 _mixerGrid.setFrameStyle(QFrame::NoFrame);
 _jack._master.setFixedSize(200,600);
 QHBoxLayout *r=new QHBoxLayout;
 r->addWidget(&_mixerGrid, 2);
 r->addWidget(&_jack._master);

 _layout.addLayout(menubar);
 _layout.addLayout(act);
 _layout.addStretch();
 _layout.addLayout(r, 2);
 setLayout(&_layout);
  

 connect(&_jackClientActivation, SIGNAL(clicked()),
	  this, SLOT(jackCtrlClicked()));
 connect(&_addMixer, SIGNAL(clicked()),
	  this, SLOT(addMixerClicked()));
 connect(&_removeMixer, SIGNAL(clicked()),
	  this, SLOT(removeMixerClicked()));
 connect(&_jack, SIGNAL(clientStopped()),
	  this, SLOT(jackStopped()));
 connect(&_jack, SIGNAL(receivedMidiEvent(struct MidiEvent)),
	  this, SLOT(handleMidiEvent(struct MidiEvent)), Qt::QueuedConnection);
 connect(&_jack, SIGNAL(receivedMidiEvent(struct MidiEvent)),
	  &_midiIn, SLOT(midiIn()), Qt::QueuedConnection);
 connect(&_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
	  this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
 connect(&_midiIn, SIGNAL(inputChannelChanged(int)),
	  &_jack, SLOT(setInputChannel(int)));
}

void Injector::timerEvent(QTimerEvent *event) {
 if (event->timerId() == _timerID) {
   _jack.refreshVu();
 }
 QWidget::timerEvent(event);
}

void Injector::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
  if (reason == QSystemTrayIcon::Trigger) {
    if (!isVisible()) {
      show();
    }
    else {
      _geoMem=geometry();
      hide();
    }
  }
  if (reason == QSystemTrayIcon::Context) {
    //QPoint pos=mapFromGlobal(QCursor::pos());
    //QMouseEvent ev(QEvent::MouseButtonPress, pos, Qt::RightButton, Qt::RightButton, Qt::NoModifier);
    
    //mousePressEvent(&ev);
    if (!_menu) {
      _menu=new QMenu(this);
      _menu->addAction(QIcon(QPixmap(":/exit")), "Close", this, SLOT(close()));
    }
    _menu->exec(QCursor::pos());//mapToGlobal(ev->pos()));

  }
}
void Injector::jackStopped() {
  _jackClientActivation.setText(tr("Start"));
  killTimer(_timerID);
}

void Injector::jackCtrlClicked()
{

  if (_jack.isActive()) {
    _jack.closeClient();
  }
  else {
    if (_jack.initEngine(_clientName)) {
      _jackClientActivation.setText(tr("Stop"));
      int refresh=float(_jack.getBlockSize()) / _jack.getSamplerate() * 1000;
      qWarning() << "starting timer, suggested refresh timùe is "<<refresh;
      _timerID=startTimer(refresh > 50 ? refresh : 50);
    }
    else
      QMessageBox::warning(this, tr("Error"), 
               tr("Jack failed to initialise..."));
  }

}
void Injector::addMixerClicked()
{
  bool ok;
  QString name=QInputDialog::getText(this, tr("New input mixer"),
				     tr("Input mixer name:"), QLineEdit::Normal,
                     QString("通道%1").arg(_mixerGrid.columnCount()),
				     &ok);
  if (ok && !name.isEmpty()) {
    VolumeMeter *vm=new VolumeMeter(name);
    if (!_jack.addMixer(vm)) {
      delete vm;
      return;
    }
    //vm->setAutoFillBackground(true);
    //connect(&_vuTimer, SIGNAL(timeout()), vm, SLOT(refresh()));
    _mixerGrid.setColumnCount(_mixerGrid.columnCount() + 1);
    _mixerGrid.setCellWidget(0, _mixerGrid.columnCount() - 1, vm);

  }
}
void Injector::removeMixerClicked()
{
  QStringList items;
  int i;
  VolumeMeter *vm;
  for (i=0; i < _mixerGrid.columnCount(); i++) {
    vm=(VolumeMeter*)_mixerGrid.cellWidget(0, i);
    items << vm->getID();
  }
  bool ok;
  QString item=QInputDialog::getItem(this, tr("Delete input mixer"),
				       tr("Delete input mixer:"), items, 0, false, &ok);
  if (ok && !item.isEmpty()) {
    for (i=0; i < _mixerGrid.columnCount(); i++) {
      vm=(VolumeMeter*)_mixerGrid.cellWidget(0, i);
      if (item == vm->getID()) {
	_jack.removeMixer(vm);
	_mixerGrid.removeCellWidget(0, i);
	_mixerGrid.removeColumn(i);
	return;
      }
    }
  }
}

void Injector::handleMidiEvent(struct MidiEvent ev)
{
  if ((ev.data[0] & 0xF0) == MIDI_CONTROLLER) {
    __midiWidgetMap.midiCCEvent(ev.data[1], ev.data[2]);
  }
  else if ((ev.data[0] & 0xF0) == MIDI_NOTE_ON) {
    __midiWidgetMap.midiNoteEvent(true, ev.data[1], ev.data[2]);
  }
  else if ((ev.data[0] & 0xF0) == MIDI_NOTE_OFF) {
    __midiWidgetMap.midiNoteEvent(false, ev.data[1], ev.data[2]);
  }
}

bool Injector::saveConf() 
{
  QDomDocument conf;
  QDomProcessingInstruction instr;
  instr=conf.createProcessingInstruction("xml", "version=\"1.0\"  encoding=\"UTF-8\"");
  conf.appendChild(instr);
  QDomElement root, midi, params, mixer, mixers;
  root=conf.createElement("rhdzConf");
  root.setAttribute("xmlns", "http://staxaudio.free.fr/mime-info");
  conf.appendChild(root);

  bool vis=isVisible();
  QRect dims=geometry();
  if (!vis) {
    dims=_geoMem;
  }
  else
    dims=geometry();
  params=conf.createElement("geometry");
  params.setAttribute("visible", vis);
  params.setAttribute("x", dims.x());
  params.setAttribute("y", dims.y());
  params.setAttribute("width", dims.width());
  params.setAttribute("height", dims.height());
  root.appendChild(params);

  root.appendChild(_jack.connectionsToXML());

  mixers=conf.createElement("mixers");
  for (int i=0; i < _mixerGrid.columnCount(); i++) {
    mixer=conf.createElement("mixer");
    VolumeMeter *vm=(VolumeMeter*)_mixerGrid.cellWidget(0, i);
    mixer.setAttribute("id", vm->getID());
    mixer.setAttribute("index", i);
    mixers.appendChild(mixer);
  }
  root.appendChild(mixers);
  root.appendChild(__midiWidgetMap.midiCtrlsToXML());
  root.appendChild(__midiWidgetMap.midiMapToXML());
  root.appendChild(_midiIn.toXML(conf));

  QFile f(_confFile);
  if (!f.open(QIODevice::WriteOnly))
    return false;
  QTextStream ts(&f);
  ts << conf.toString();
  f.close();


  return true;
}
bool Injector::loadConf() 
{
  QDomDocument conf;
  QFile f(_confFile);
  if (!f.open(QIODevice::ReadOnly))
    return false;
  QString errorStr;
  int errorLine, errorColumn;
  if (!conf.setContent(&f, true, &errorStr, &errorLine, &errorColumn)) {
    qDebug()<<"Parse error at line "<<errorLine<< ", column "<<errorColumn<<":"<<errorStr;
    f.close();
    return false;
  }
  f.close();
  QDomElement root=conf.documentElement();
  if (root.tagName() != "InjectorConf") {
    qDebug()<<"The file is not a conf file for this app.";
    return false;
  }

  QDomNodeList geo=conf.elementsByTagName("geometry");
  QDomElement elt;
  
  if (geo.length()) {
    elt=geo.item(0).toElement();
    _geoMem.setRect(elt.attribute("x").toInt(), elt.attribute("y").toInt(),
		    elt.attribute("width").toInt(), elt.attribute("height").toInt());
    setGeometry(_geoMem);
    if (elt.attribute("visible").toInt())
      show();
    else
      hide();
  }

  QDomNodeList mixers=conf.elementsByTagName("mixers");
  if (mixers.length()) {
    mixers=mixers.item(0).childNodes();
    _mixerGrid.setColumnCount(mixers.length());
    for (uint i=0; i < mixers.length(); i++) {
      QDomElement mixer=mixers.item(i).toElement();
      VolumeMeter *vm=new VolumeMeter(mixer.attribute("id"));
      if (!_jack.addMixer(vm)) {
	delete vm;
      }
      else {
	int index=mixer.attribute("index").toInt();
	_mixerGrid.setCellWidget(0, index, vm);
      }
    }
  }
  __midiWidgetMap.midiCtrlsFromXML(root);
  __midiWidgetMap.midiMapFromXML(root);
  _jack.connectionsFromXML(root);
  _midiIn.fromXML(root);
  return true;
}


// 
// injector.cpp ends here
