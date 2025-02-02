/* midi_widgets.h --- 
 * 
 * Filename: midi_widgets.h
 * Description: 
 * Author: stax
 * Maintainer: 
 * Created: lun oct 12 18:13:44 2009 (+0200)
 * Version: 
 * Last-Updated: sam. janv. 16 02:05:25 2016 (+0100)
 *           By: stax
 *     Update #: 73
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

#ifndef MIDI_WIDGETS_H
#define MIDI_WIDGETS_H

#include <QtGui>
#include <QtXml>
#include <QtWidgets>
#include <QLabel>
#define LEARN_NOTE	1
#define LEARN_CC	2

class MidiInputBox : public QGroupBox
{
  Q_OBJECT
 private:
  QLabel _lbl;
  QComboBox _inputChannel;
  QTimer _ledTimer;

 private slots:
  void inputChanSelChanged(int);
  void ledOff();

 public:
  MidiInputBox();

  QDomElement toXML(QDomDocument);
  void fromXML(QDomElement);

 public slots:
  void midiIn();

 signals:
  void inputChannelChanged(int);
};
class MidiOutputBox : public QGroupBox
{
  Q_OBJECT
 private:
  QLabel _lbl;
  QTimer _ledTimer;

 private slots:
  void ledOff();

 public:
  MidiOutputBox();

 public slots:
  void midiOut();
};

// a basic dialog to state learn mode
class MidiLearnerDlg : public QDialog
{
  Q_OBJECT

private:
  int _value;
  int _learnType;
  QLabel _label;
  QPushButton _butCancel, _butReset;

public:
  MidiLearnerDlg(QWidget *parent=NULL);
  //~MidiLearnerDlg();
  
  int getValue() {return _value;}
  void setValue(int val) {_value=val;}
  int getLearnType() {return _learnType;}
  void setLearnType(int val);

public slots:
  void learnReset();
};

// a basic midi button
class Midibut : public QPushButton
{
Q_OBJECT
private:
  QString _midiID, _midiGroup;
  int _midiNote;
  void mousePressEvent(QMouseEvent *ev);

public:
  Midibut();
  ~Midibut();

  void handleMidiNote(bool on, unsigned char id, unsigned char value);

  void setMidiID(QString id);
  void setMidiNote(int cc) {_midiNote=cc;}
  int getMidiNote() {return _midiNote;}
  void setMidiGroup(QString g) {_midiGroup=g;}
  QString getMidiGroup() {return _midiGroup;}

signals:
  void midiLearnRequest(QString);

};

// a parametric QDial [0..127]
class Knob : public QDial
{
Q_OBJECT
private:
  float _paramMin, _paramMax;
  bool _orderAsc;
  bool _exactMidRange;

public:
  Knob();
  void setParamOrder(bool asc) {_orderAsc=asc;}
  void setExactMidRange(bool mid) {_exactMidRange=mid;}
  void setParamRange(float, float);
  float getParamValue();
};

// a parametric QSlider [0..127]
class Fader : public QSlider
{
Q_OBJECT
private:
  float _paramMin, _paramMax;
  bool _orderAsc;
  bool _exactMidRange;

public:
  Fader();
  void setParamOrder(bool asc) {_orderAsc=asc;}
  void setExactMidRange(bool mid) {_exactMidRange=mid;}
  void setParamRange(float, float);
  float getParamValue();
};

// a basic midi knob
class Midiknob : public QWidget
{
Q_OBJECT
private:
  Knob _knob;
  QLabel _label;
  QVBoxLayout _layout;
  QString _midiID, _midiGroup;
  int _midiCC;

  void mousePressEvent(QMouseEvent *ev);

private slots:
  void knobValChanged(int);

public:
  Midiknob();
  ~Midiknob();

  void initKnob(QString id, float min, float max, int value,
		bool asc=true, bool exactmid=false);

  void handleMidi(unsigned char id, unsigned char value);

  void setMidiID(QString id);
  void setMidiCC(int cc) {_midiCC=cc;}
  int getMidiCC() {return _midiCC;}
  void setMidiGroup(QString g) {_midiGroup=g;}
  QString getMidiGroup() {return _midiGroup;}

  void setLabel(QString lbl) {_label.setText(lbl);}

  void setValue(int val) {_knob.setValue(val);}
  int value() {return _knob.value();}
  void setParamOrder(bool asc) {_knob.setParamOrder(asc);}
  void setExactMidRange(bool mid) {_knob.setExactMidRange(mid);}
  void setParamRange(float min, float max) {_knob.setParamRange(min, max);}
  float getParamValue() {return _knob.getParamValue();}

signals:
  void valueChanged(float);
  void midiLearnRequest(QString);
};

// a basic midi fader
class Midifader : public QWidget
{
Q_OBJECT
private:
  Fader _fader;
  QLabel _label;
  QVBoxLayout _layout;
  QString _midiID, _midiGroup;
  int _midiCC;

  void mousePressEvent(QMouseEvent *ev);

private slots:
  void faderValChanged(int);

public:
  Midifader();
  ~Midifader();

  void initFader(QString id, float min, float max, int value,
		 bool asc=true, bool exactmid=false);

  void handleMidi(unsigned char id, unsigned char value);

  void setOrientation(Qt::Orientation);
  void setMidiID(QString id);
  void setMidiCC(int cc) {_midiCC=cc;}
  int getMidiCC() {return _midiCC;}
  void setMidiGroup(QString g) {_midiGroup=g;}
  QString getMidiGroup() {return _midiGroup;}

  void setLabel(QString lbl) {_label.setText(lbl);}

  void setValue(int val) {_fader.setValue(val);}
  int value() {return _fader.value();}
  void setParamOrder(bool asc) {_fader.setParamOrder(asc);}
  void setExactMidRange(bool mid) {_fader.setExactMidRange(mid);}
  void setParamRange(float min, float max) {_fader.setParamRange(min, max);}
  float getParamValue() {return _fader.getParamValue();}

signals:
  void valueChanged(float);
  void midiLearnRequest(QString);
};

// a midi widget mapper
class MidiWidgetMap : public QObject
{
Q_OBJECT
private:
  QMap<QString, Midiknob*> _knobs;
  QMap<QString, Midifader*> _faders;
  QMap<QString, Midibut*> _buts;
  MidiLearnerDlg *_midiLearner;

public:
  MidiWidgetMap();

  void mapKnob(QString, Midiknob*);
  void mapFader(QString, Midifader*);
  void mapBut(QString, Midibut*);
  void unmapKnob(QString);
  void unmapFader(QString);
  void unmapBut(QString);
  void setMidiLearner(MidiLearnerDlg *ml) {_midiLearner=ml;}

  void midiCCEvent(unsigned char id, unsigned char value);
  void midiNoteEvent(bool on, unsigned char id, unsigned char value);

  void fromXML(bool midi, QDomElement, QString group="");
  QDomElement toXML(bool midi, QString group="");

  void midiMapFromXML(QDomElement e, QString group="") {fromXML(true, e, group);}
  QDomElement midiMapToXML(QString group="") {return toXML(true, group);}
  void midiCtrlsFromXML(QDomElement e, QString group="") {fromXML(false, e, group);}
  QDomElement midiCtrlsToXML(QString group="") {return toXML(false, group);}

public slots:
  void learnKnob(QString);
  void learnFader(QString);
  void learnBut(QString);
};

extern MidiWidgetMap __midiWidgetMap;

#endif

/* midi_widgets.h ends here */
