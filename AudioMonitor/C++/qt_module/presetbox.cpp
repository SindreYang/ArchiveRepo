// presetbox.cpp --- 
// 
// Filename: presetbox.cpp
// Description: 
// Author: stax
// Maintainer: 
// Created: mar oct 27 17:01:06 2009 (+0100)
// Version: 
// Last-Updated: mar. oct. 10 01:13:59 2017 (+0200)
//           By: stax
//     Update #: 44
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change log:
// 
// 
// 
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth
// Floor, Boston, MA 02110-1301, USA.
// 
// 

#include "presetbox.h"

PresetBox::PresetBox()
{
  for (int i=0; i < 128; i++)
    addItem(tr("[%1] - <empty>").arg(i));
}

void PresetBox::setPreset(int index, QString name, QDomElement e)
{
  e.setAttribute("index", index);
  e.setAttribute("name", name);
  QVariant v;
  v.setValue(e);
  setItemData(index, v);
  setItemText(index, tr("[%1] - %2").arg(index).arg(name));
}
void PresetBox::clearPreset(int index)
{
  setItemData(index, 0);
  setItemText(index, tr("[%1] - <empty>").arg(index));
}
QDomElement PresetBox::toXML()
{
  QDomDocument conf;
  QDomElement l=conf.createElement("presets");
  for (int i=0; i < count(); i++)
    if (!itemData(i).isNull()) {
      QDomElement p=itemData(i).value<QDomElement>();
      l.appendChild(p);
    }
  return l;
}

void PresetBox::fromXML(QDomElement e)
{
  clear();
  for (int i=0; i < 128; i++)
    addItem(tr("[%1] - <empty>").arg(i));
  QDomNodeList l=e.elementsByTagName("preset");
  for (uint i=0; i < l.length(); i++) {
    QDomElement p=l.item(i).toElement();
    int index=p.attribute("index").toInt();
    QVariant v;
    v.setValue(p);
    setItemData(index, v);
    setItemText(index, tr("[%1] - %2").arg(index).arg(p.attribute("name")));
  }
}

bool PresetBox::savePresets(QString name, QString path, QString xmlns) 
{
  QDomDocument conf;
  QDomProcessingInstruction instr;
  instr=conf.createProcessingInstruction("xml", "version=\"1.0\"  encoding=\"UTF-8\"");
  conf.appendChild(instr);
  QDomElement root;
  root=conf.createElement(name);
  root.setAttribute("xmlns", xmlns);
  conf.appendChild(root);

  root.appendChild(toXML());

  QFile f(path);
  if (!f.open(QIODevice::WriteOnly))
    return false;
  QTextStream ts(&f);
  ts << conf.toString();
  f.close();

  return true;
}
bool PresetBox::loadPresets(QString name, QString path) 
{
  QDomDocument conf;
  QFile f(path);
  if (!f.open(QIODevice::ReadOnly))
    return false;
  QString errorStr;
  int errorLine, errorColumn;
  if (!conf.setContent(&f, false, &errorStr, &errorLine, &errorColumn)) {
    qDebug()<<"Parse error at line "<<errorLine<< ", column "<<errorColumn<<":"<<errorStr;
    f.close();
    return false;
  }
  f.close();
  QDomElement root=conf.documentElement();
  if (root.tagName() != name) {
    qDebug()<<"The file is not a conf file for this app.";
    return false;
  }

  fromXML(root);

  if (currentIndex() == 0)
    emit currentIndexChanged(0);
  else
    setCurrentIndex(0);

  return true;
}


//
PresetManager::PresetManager()
{
  _presetName.hide();
  _savePreset.setIcon(QIcon(QPixmap(":/preset_save_as")));
  _clearPreset.setIcon(QIcon(QPixmap(":/preset_clear")));
  _presetName.setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
  QHBoxLayout *l=new QHBoxLayout;
  l->addWidget(&_presetBox, 1);
  l->addWidget(&_presetName, 1);
  l->addWidget(&_savePreset);
  l->addWidget(&_clearPreset);
  l->addStretch(1);
  setLayout(l);

  connect(&_savePreset, SIGNAL(clicked()),
	  this, SLOT(savePresetClicked()));
  connect(&_clearPreset, SIGNAL(clicked()),
	  this, SLOT(clearPresetClicked()));
  connect(&_presetName, SIGNAL(returnPressed()),
	  this, SLOT(savePresetClicked()));
  connect(&_presetBox, SIGNAL(currentIndexChanged(int)),
	  this, SLOT(curPresetChanged(int)));
}
void PresetManager::setPresetFile(QString name, QString path, QString xmlns)
{
  _presetLabel=name;
  _presetFile=path;
  _presetXMLNS=xmlns;
}
bool PresetManager::loadPresets()
{
  if (_presetLabel.isEmpty() || _presetFile.isEmpty())
    return false;
  return _presetBox.loadPresets(_presetLabel, _presetFile);
}
bool PresetManager::savePresets()
{
  if (_presetLabel.isEmpty() || _presetFile.isEmpty())
    return false;
  return _presetBox.savePresets(_presetLabel, _presetFile, _presetXMLNS);
}
void PresetManager::curPresetChanged(int cur)
{
  if (cur < 0)
    return;
  if (_presetBox.isPresetSet(cur)) {
    QDomElement pres=_presetBox.getPreset(cur);
    emit presetChanged(pres);
  }
}
void PresetManager::savePresetClicked()
{
  int index=_presetBox.currentIndex();
  if (_presetName.isVisible()) {
    if (_presetName.text().isEmpty())
      return;
    QString name=_presetName.text();
    emit savePresetRequest(index, name);
  }
  else {
    _presetBox.hide();
    if (_presetBox.isPresetSet(index))
      _presetName.setText(_presetBox.getPreset(index).attribute("name"));
    else
      _presetName.setText(QString("preset%1").arg(index));
    _presetName.selectAll();
    _presetName.show();
    _presetName.setFocus();
    _savePreset.setIcon(QIcon(QPixmap(":/preset_save")));
  }

}
void PresetManager::clearPresetClicked()
{
  _presetBox.clearPreset(_presetBox.currentIndex());
}
void PresetManager::setPreset(int index, QString name, QDomElement pres)
{
  _presetBox.setPreset(index, name, pres);
  savePresets();
  _presetName.hide();
  _presetBox.show();
  _savePreset.setIcon(QIcon(QPixmap(":/preset_save_as")));
}
// 
// presetbox.cpp ends here
