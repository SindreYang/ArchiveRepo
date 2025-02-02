/* midi_widgets.c --- 
 * 
 * Filename: midi_widgets.c
 * Description: 
 * Author: stax
 * Maintainer: 
 * Created: lun oct 12 18:14:52 2009 (+0200)
 * Version: 
 * Last-Updated: sam. janv. 16 02:05:08 2016 (+0100)
 *           By: stax
 *     Update #: 155
 * URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 */

#include <math.h>
#include "midi_widgets.h"


MidiInputBox::MidiInputBox()
{
  setTitle("Midi input");
  _lbl.setPixmap(QPixmap(":/led_off"));
  _inputChannel.addItem("Any channel", -1);
  for (int i=0; i < 16; i++)
    _inputChannel.addItem(QString("Channel %1").arg(i + 1), i);
  QHBoxLayout *lo=new QHBoxLayout;
  lo->addWidget(&_lbl);
  lo->addWidget(&_inputChannel);
  setLayout(lo);
  _ledTimer.setInterval(200);
  _ledTimer.setSingleShot(true);
  connect(&_ledTimer, SIGNAL(timeout()), this, SLOT(ledOff()));
  connect(&_inputChannel, SIGNAL(currentIndexChanged(int)), 
	  this, SLOT(inputChanSelChanged(int)));
}
void MidiInputBox::inputChanSelChanged(int idx)
{
  if (idx >= 0)
    emit inputChannelChanged(_inputChannel.itemData(idx).toInt());
}
void MidiInputBox::midiIn()
{
  _lbl.setPixmap(QPixmap(":/led_on"));
  _ledTimer.start();
}
void MidiInputBox::ledOff()
{
  _lbl.setPixmap(QPixmap(":/led_off"));
}
void MidiInputBox::fromXML(QDomElement root)
{
  QDomNodeList ml;
  ml=root.elementsByTagName("jack_midi_input_channel");    
  if (!ml.length())
    return;
  QDomElement e=ml.item(0).toElement();
  int chan=e.attribute("value").toInt();
  for (int i=0; i < _inputChannel.count(); i++)
    if (_inputChannel.itemData(i).toInt() == chan) {
      _inputChannel.setCurrentIndex(i);
      return;
    }
}
QDomElement MidiInputBox::toXML(QDomDocument conf)
{
  QDomElement e=conf.createElement("jack_midi_input_channel");
  e.setAttribute("value", _inputChannel.itemData(_inputChannel.currentIndex()).toInt());
  return e;
}
//
MidiOutputBox::MidiOutputBox()
{
  setTitle("Midi output");
  _lbl.setPixmap(QPixmap(":/led_off"));

  QHBoxLayout *lo=new QHBoxLayout;
  lo->addWidget(&_lbl);
  lo->setAlignment(&_lbl, Qt::AlignCenter);
  setLayout(lo);
  _ledTimer.setInterval(200);
  _ledTimer.setSingleShot(true);
  connect(&_ledTimer, SIGNAL(timeout()), this, SLOT(ledOff()));
}
void MidiOutputBox::midiOut()
{
  _lbl.setPixmap(QPixmap(":/led_on"));
  _ledTimer.start();
}
void MidiOutputBox::ledOff()
{
  _lbl.setPixmap(QPixmap(":/led_off"));
}

//
MidiLearnerDlg::MidiLearnerDlg(QWidget *parent) : QDialog(parent), _butCancel(tr("Cancel"), this), _butReset(tr("Reset (no midi event)"), this)
{
  _label.setAlignment(Qt::AlignCenter);
  setLearnType(LEARN_CC);
  QVBoxLayout *lo=new QVBoxLayout;
  lo->addWidget(&_label, 0, Qt::AlignCenter);
  lo->addWidget(&_butReset);
  lo->addWidget(&_butCancel);
  _butCancel.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  connect(&_butCancel, SIGNAL(clicked()), this, SLOT(reject()));
  connect(&_butReset, SIGNAL(clicked()), this, SLOT(learnReset()));
  setLayout(lo);
  setWindowModality(Qt::WindowModal);
  setAttribute(Qt::WA_QuitOnClose, false);
  _value=-1;
}
/*
MidiLearnerDlg::~MidiLearnerDlg()
{
  
  QLayout *l=layout();
  if (l)
    delete layout();
  
}
*/
void MidiLearnerDlg::setLearnType(int val)
{
  _learnType=val;
  if (val == LEARN_NOTE)
    _label.setText(tr("Learning midi note ...\nhit a note on your midi device"));
  else
    _label.setText(tr("Learning midi control ...\nmove a knob or fadder on your midi device"));
}

void MidiLearnerDlg::learnReset()
{
  _value=-1;
  accept();
}



MidiWidgetMap __midiWidgetMap;

//
Knob::Knob()
{
  setFixedSize(50, 50);
  setRange(0, 127);
  setSingleStep(1);
  setNotchesVisible(true);
  _paramMin=_paramMax=0;
  _orderAsc=true;
  _exactMidRange=false;
}
void Knob::setParamRange(float min, float max)
{
  _paramMin=min;
  _paramMax=max;
}
float Knob::getParamValue()
{

  float val;
  if (_orderAsc)
    val=value();
  else
    val=127 - value();
  if (_exactMidRange && (value() == 63))
    val=_paramMin + (0.5 * (_paramMax - _paramMin));
  else
    val=_paramMin + (val / 127.0) * (_paramMax - _paramMin);

  return val;
}
//
Fader::Fader()
{
  setRange(0, 127);
  setSingleStep(1);

  QString stylesheet="QSlider::handle:vertical {image:url(:/vslider);}";
  stylesheet+="QSlider::handle:horizontal {image:url(:/hslider);}";
  stylesheet+="QSlider::groove:vertical {image:url(:/vslider_groove);}";
  stylesheet+="QSlider::groove:horizontal {image:url(:/hslider_groove);}";
  setStyleSheet(stylesheet);

  _paramMin=_paramMax=0;
  _orderAsc=true;
  _exactMidRange=false;
}
void Fader::setParamRange(float min, float max)
{
  _paramMin=min;
  _paramMax=max;
}
float Fader::getParamValue()
{

  float val;
  if (_orderAsc)
    val=value();
  else
    val=127 - value();
  if (_exactMidRange && (value() == 63))
    val=_paramMin + (0.5 * (_paramMax - _paramMin));
  else
    val=_paramMin + (val / 127.0) * (_paramMax - _paramMin);

  return val;
}

//
Midiknob::Midiknob()
{
 
  _midiCC=-1;
  _label.setAlignment(Qt::AlignCenter);
  _layout.addWidget(&_knob, 0, Qt::AlignHCenter|Qt::AlignBottom);
  _layout.addWidget(&_label, 0, Qt::AlignHCenter|Qt::AlignTop);
  _layout.setContentsMargins(0, 0, 0, 0);
  setLayout(&_layout);
  connect(&_knob, SIGNAL(valueChanged(int)), this, SLOT(knobValChanged(int)));
}
Midiknob::~Midiknob()
{
  if (!_midiID.isEmpty())
    __midiWidgetMap.unmapKnob(_midiID);
}
void Midiknob::initKnob(QString id, float min, float max, int value,
			 bool asc, bool exactmid)
{
  _knob.setParamRange(min, max);
  _knob.setParamOrder(asc);
  _knob.setExactMidRange(exactmid);

  if (value != _knob.value())
    _knob.setValue(value);
  //else
  //_knob.valueChanged(value);
  if (!id.isEmpty())
    setMidiID(id);
}
void Midiknob::setMidiID(QString id)
{
  _midiID=id;
  __midiWidgetMap.mapKnob(id, this);
}
void Midiknob::knobValChanged(int)
{
  emit valueChanged(_knob.getParamValue());
}
void Midiknob::mousePressEvent(QMouseEvent *ev)
{
  if (ev->buttons() & Qt::RightButton) {
    ev->accept();
    emit midiLearnRequest(_midiID);
  }
}
void Midiknob::handleMidi(unsigned char id, unsigned char value)
{
  if (_midiCC == id)
    _knob.setValue(value);
}


//
Midifader::Midifader()
{
 
  _midiCC=-1;
  setOrientation(Qt::Vertical);
  _label.setAlignment(Qt::AlignCenter);
  _layout.addWidget(&_fader, 3);
  _layout.addWidget(&_label, 0, Qt::AlignHCenter);
  _layout.setContentsMargins(0, 0, 0, 0);
  setLayout(&_layout);
  connect(&_fader, SIGNAL(valueChanged(int)), this, SLOT(faderValChanged(int)));
}
Midifader::~Midifader()
{
  if (!_midiID.isEmpty())
    __midiWidgetMap.unmapFader(_midiID);
}
void Midifader::initFader(QString id, float min, float max, int value,
			  bool asc, bool exactmid)
{
  _fader.setParamRange(min, max);
  _fader.setParamOrder(asc);
  _fader.setExactMidRange(exactmid);
  if (value != _fader.value())
    _fader.setValue(value);
    
  if (!id.isEmpty())
    setMidiID(id);
}
void Midifader::setOrientation(Qt::Orientation o)
{
  _fader.setOrientation(o);
  if (o != Qt::Vertical)
    _fader.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
  else
    _fader.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
}
void Midifader::setMidiID(QString id)
{
  _midiID=id;
  __midiWidgetMap.mapFader(id, this);
}
void Midifader::faderValChanged(int)
{
  emit valueChanged(_fader.getParamValue());
}
void Midifader::mousePressEvent(QMouseEvent *ev)
{
  if (ev->buttons() & Qt::RightButton) {
    ev->accept();
    emit midiLearnRequest(_midiID);
  }
}
void Midifader::handleMidi(unsigned char id, unsigned char value)
{
  if (_midiCC == id)
    _fader.setValue(value);
}

//
Midibut::Midibut()
{ 
  _midiNote=-1;
}
Midibut::~Midibut()
{ 
  if (!_midiID.isEmpty())
    __midiWidgetMap.unmapBut(_midiID);
}
void Midibut::setMidiID(QString id)
{
  _midiID=id;
  __midiWidgetMap.mapBut(id, this);
}
void Midibut::mousePressEvent(QMouseEvent *ev)
{
  if (ev->buttons() & Qt::RightButton) {
    ev->accept();
    emit midiLearnRequest(_midiID);
  }
  else
    QPushButton::mousePressEvent(ev);
}
void Midibut::handleMidiNote(bool on, unsigned char id, unsigned char)
{
  if (_midiNote == id) {
    if (on && isCheckable()) {
      setChecked(!isChecked());
      //emit toggled(isChecked());
    }
    else {
      if (on) {
	setDown(true);
	emit pressed();
      }
      else {
	setDown(false);
	emit released();
      }
    }
  }
}

//
MidiWidgetMap::MidiWidgetMap()
{
  _midiLearner=NULL;
}
void MidiWidgetMap::midiCCEvent(unsigned char id, unsigned char value)
{
  if (_midiLearner && _midiLearner->isVisible() &&
      (_midiLearner->getLearnType() == LEARN_CC)) {
    _midiLearner->setValue(id);
    _midiLearner->accept();
    return;
  }
  foreach (Midiknob *knob, _knobs) {
    knob->handleMidi(id, value);
  }
  foreach (Midifader *fader, _faders) {
    fader->handleMidi(id, value);
  }
}
void MidiWidgetMap::midiNoteEvent(bool on, unsigned char id, unsigned char value)
{
  if (_midiLearner && _midiLearner->isVisible() &&
      (_midiLearner->getLearnType() == LEARN_NOTE)) {
    _midiLearner->setValue(id);
    _midiLearner->accept();
    return;
  }
  foreach (Midibut *but, _buts) {
    but->handleMidiNote(on, id, value);
  }
}
void MidiWidgetMap::mapKnob(QString id, Midiknob *knob)
{
  _knobs[id]=knob;
  connect(knob, SIGNAL(midiLearnRequest(QString)),
	  this, SLOT(learnKnob(QString)));
}
void MidiWidgetMap::mapFader(QString id, Midifader *fader)
{
  _faders[id]=fader;
  connect(fader, SIGNAL(midiLearnRequest(QString)),
	  this, SLOT(learnFader(QString)));
}
void MidiWidgetMap::mapBut(QString id, Midibut *but)
{
  _buts[id]=but;
  connect(but, SIGNAL(midiLearnRequest(QString)),
	  this, SLOT(learnBut(QString)));
}
void MidiWidgetMap::unmapKnob(QString id)
{
  if (_knobs.contains(id))
    _knobs.remove(id);
}
void MidiWidgetMap::unmapFader(QString id)
{
  if (_faders.contains(id))
    _faders.remove(id);
}
void MidiWidgetMap::unmapBut(QString id)
{
  if (_buts.contains(id))
    _buts.remove(id);
}
void MidiWidgetMap::learnKnob(QString id)
{
  qDebug()<<id<<"query learn";
  if (_midiLearner && _knobs[id]) {
    int w=_midiLearner->width();
    int h=_midiLearner->height();
    _midiLearner->setGeometry((QApplication::desktop()->width() - w) / 2,
			      (QApplication::desktop()->height() - h) / 2,
			      w, h);
    _midiLearner->setLearnType(LEARN_CC);
    _midiLearner->setWindowTitle(tr("Learning knob %1 ...").arg(id));
    if (_midiLearner->exec() == QDialog::Accepted) {
      qDebug()<<"learned"<<_midiLearner->getValue();
      _knobs[id]->setMidiCC(_midiLearner->getValue());
    }
  }
}
void MidiWidgetMap::learnFader(QString id)
{
  qDebug()<<id<<"query learn";
  if (_midiLearner && _faders[id]) {
    int w=_midiLearner->width();
    int h=_midiLearner->height();
    _midiLearner->setGeometry((QApplication::desktop()->width() - w) / 2,
			      (QApplication::desktop()->height() - h) / 2,
			      w, h);
    _midiLearner->setLearnType(LEARN_CC);
    _midiLearner->setWindowTitle(tr("Learning fader %1 ...").arg(id));
    if (_midiLearner->exec() == QDialog::Accepted) {
      qDebug()<<"learned"<<_midiLearner->getValue();
      _faders[id]->setMidiCC(_midiLearner->getValue());
    }
  }
}
void MidiWidgetMap::learnBut(QString id)
{
  qDebug()<<id<<"query learn";
  if (_midiLearner && _buts[id]) {
    int w=_midiLearner->width();
    int h=_midiLearner->height();
    _midiLearner->setGeometry((QApplication::desktop()->width() - w) / 2,
			      (QApplication::desktop()->height() - h) / 2,
			      w, h);

    _midiLearner->setLearnType(LEARN_NOTE);
    _midiLearner->setWindowTitle(tr("Learning button %1 ...").arg(id));
    if (_midiLearner->exec() == QDialog::Accepted) {
      qDebug()<<"learned"<<_midiLearner->getValue();
      _buts[id]->setMidiNote(_midiLearner->getValue());
    }
  }
}
void MidiWidgetMap::fromXML(bool midi, QDomElement root, QString group)
{
  QDomNodeList ml;
  if (midi)
    ml=root.elementsByTagName("midi_map");
  else
    ml=root.elementsByTagName("midi_ctrls");
    
  if (!ml.length())
    return;

  QDomElement map;
  //  if (!group.isEmpty()) {
    uint idx=0;
    do { 
      map=ml.item(idx).toElement();
      idx++;
    } while((idx < ml.length()) && (map.attribute("group") != group));
    if (map.attribute("group") != group)
      return;
    //}
    //else
    // map=ml.item(0).toElement();

  ml=map.childNodes();
  for (uint i=0; i < ml.length(); i++) {
    QDomElement e=ml.item(i).toElement();
    if (_knobs.contains(e.tagName())) {
      if (midi)
	_knobs[e.tagName()]->setMidiCC(e.attribute("midi_cc").toInt());
      else
	_knobs[e.tagName()]->setValue(e.attribute("value").toInt());	
    }
    else if (_faders.contains(e.tagName())) {
      if (midi)
	_faders[e.tagName()]->setMidiCC(e.attribute("midi_cc").toInt());
      else
	_faders[e.tagName()]->setValue(e.attribute("value").toInt());	
    }
    else if (_buts.contains(e.tagName())) {
      if (midi)
	_buts[e.tagName()]->setMidiNote(e.attribute("midi_note").toInt());
      else if (_buts[e.tagName()]->isCheckable())
	_buts[e.tagName()]->setChecked(e.attribute("value").toInt());
    }
  }
  /*
  QMap<QString, Midiknob*>::const_iterator i=_knobs.constBegin();
  while (i != _knobs.constEnd()) {
    if (group.isEmpty() ||
	(!group.isEmpty() && (i.value()->getMidiGroup() == group))) {
      QDomNodeList kl=map.elementsByTagName(i.key());
      if (kl.length()) {
	QDomElement k=kl.item(0).toElement();
	if (midi)
	  i.value()->setMidiCC(k.attribute("midi_cc").toInt());
	else
	  i.value()->setValue(k.attribute("value").toInt());	
      }
    }
    i++;
  }

  QMap<QString, Midifader*>::const_iterator j=_faders.constBegin();
  while (j != _faders.constEnd()) {
    if (group.isEmpty() ||
	(!group.isEmpty() && (j.value()->getMidiGroup() == group))) {
      QDomNodeList fl=map.elementsByTagName(j.key());
      if (fl.length()) {
	QDomElement f=fl.item(0).toElement();
	if (midi)
	  j.value()->setMidiCC(f.attribute("midi_cc").toInt());
	else
	  j.value()->setValue(f.attribute("value").toInt());
      }
    }
    j++;
  }

  QMap<QString, Midibut*>::const_iterator n=_buts.constBegin();
  while (n != _buts.constEnd()) {
    if (group.isEmpty() ||
	(!group.isEmpty() && (n.value()->getMidiGroup() == group))) {
      QDomNodeList bl=map.elementsByTagName(n.key());
      if (bl.length()) {
	QDomElement b=bl.item(0).toElement();
	if (midi)
	  n.value()->setMidiNote(b.attribute("midi_note").toInt());
	else if (n.value()->isCheckable())
	  n.value()->setChecked(b.attribute("value").toInt());
      }
    }
    n++;
  }
  */
}
QDomElement MidiWidgetMap::toXML(bool midi, QString group)
{
  QDomDocument conf;
  QDomElement map;
  if (midi)
    map=conf.createElement("midi_map");
  else
    map=conf.createElement("midi_ctrls");
    
  if (!group.isEmpty())
    map.setAttribute("group", group);

  QMap<QString, Midiknob*>::const_iterator i=_knobs.constBegin();
  while (i != _knobs.constEnd()) {
    if (group.isEmpty() ||
	(!group.isEmpty() && (i.value()->getMidiGroup() == group))) {
      QDomElement k=conf.createElement(i.key());
      if (midi)
	k.setAttribute("midi_cc", i.value()->getMidiCC());
      else
	k.setAttribute("value", i.value()->value());      
      map.appendChild(k);
    }
    i++;
  }

  QMap<QString, Midifader*>::const_iterator j=_faders.constBegin();
  while (j != _faders.constEnd()) {
    if (group.isEmpty() ||
	(!group.isEmpty() && (j.value()->getMidiGroup() == group))) {
      QDomElement f=conf.createElement(j.key());
      if (midi)
	f.setAttribute("midi_cc", j.value()->getMidiCC());
      else
	f.setAttribute("value", j.value()->value());      
      map.appendChild(f);
    }
    j++;
  }

  QMap<QString, Midibut*>::const_iterator n=_buts.constBegin();
  while (n != _buts.constEnd()) {
    if (group.isEmpty() ||
	(!group.isEmpty() && (n.value()->getMidiGroup() == group))) {
      QDomElement b;    
      if (midi) {
	b=conf.createElement(n.key());    
	b.setAttribute("midi_note", n.value()->getMidiNote());
	map.appendChild(b);
      }
      else
	if (n.value()->isCheckable()) {
	  b=conf.createElement(n.key());    
	  b.setAttribute("value", n.value()->isChecked());
	  map.appendChild(b);
	}
    }
    n++;
  }


  return map;
}


/* midi_widgets.c ends here */
