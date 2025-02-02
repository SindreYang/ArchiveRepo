/* presetbox.h --- 
 * 
 * Filename: presetbox.h
 * Description: 
 * Author: stax
 * Maintainer: 
 * Created: mar oct 27 16:39:31 2009 (+0100)
 * Version: 
 * Last-Updated: mer. mars  9 14:47:40 2016 (+0100)
 *           By: stax
 *     Update #: 22
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

#ifndef PRESETBOX_H
#define PRESETBOX_H

#include <QtXml>
#include <QtGui>
#include <QtWidgets>
#include <QLabel>
Q_DECLARE_METATYPE(QDomElement);

class PresetBox : public QComboBox
{
Q_OBJECT
 private:
  QDomElement toXML();
  void fromXML(QDomElement e);

 public:
  PresetBox();

  bool isPresetSet(int index) {return !itemData(index).isNull();}
  void setPreset(int index, QString name, QDomElement e);
  QDomElement getPreset(int index) {return itemData(index).value<QDomElement>();}
  void clearPreset(int index);

  bool loadPresets(QString name, QString path);
  bool savePresets(QString name, QString path, QString xmlns="");

};

class PresetManager : public QWidget
{
Q_OBJECT
 private:
  PresetBox _presetBox;
  QPushButton _savePreset, _clearPreset;
  QLineEdit _presetName;

  QString _presetLabel, _presetFile, _presetXMLNS;

 private slots:
  void savePresetClicked();
  void clearPresetClicked();
  void curPresetChanged(int);

 public:
  PresetManager();

  void setPresetFile(QString name, QString path, QString xmlns="");
  bool loadPresets();
  bool savePresets();

  void setCurrentIndex(int idx) {_presetBox.setCurrentIndex(idx);}
  int currentIndex() {return _presetBox.currentIndex();}
  void setPreset(int index, QString name, QDomElement pres);

 signals:
  void savePresetRequest(int index, QString name);
  void presetChanged(QDomElement);
};

#endif

/* presetbox.h ends here */
