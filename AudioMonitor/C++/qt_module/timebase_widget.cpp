// timebase_widget.cpp --- 
// 
// Filename: timebase_widget.cpp
// Description: 
// Author: stax
// Maintainer: 
// Created: ven nov 27 17:02:50 2009 (+0100)
// Version: 
// Last-Updated: ven nov 27 19:04:39 2009 (+0100)
//           By: stax
//     Update #: 10
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
#include "timebase_widget.h"

TimeBaseWidget::TimeBaseWidget()
{
  _samplerate=0;
  _tempo.setRange(50, 350);
  _tempo.setValue(120);
  _beatsPerBar.setRange(1, 16);
  _beatsPerBar.setValue(4);
  for (int i=1; i < 17; i*=2)
    _beatLength.addItem(QString("%1").arg(i), i);
  _beatLength.setCurrentIndex(2);

  QHBoxLayout *tb=new QHBoxLayout;
  tb->addWidget(new QLabel("tempo:"));
  tb->addWidget(&_tempo);
  tb->addStretch(1);
  tb->addWidget(new QLabel("signature:"));
  tb->addWidget(&_beatsPerBar);
  tb->addWidget(new QLabel("/"));
  tb->addWidget(&_beatLength);
  setLayout(tb);

  connect(&_tempo, SIGNAL(valueChanged(int)),
	  this, SLOT(computeTimeBase()));
  connect(&_beatsPerBar, SIGNAL(valueChanged(int)),
	  this, SLOT(computeTimeBase()));
  connect(&_beatLength, SIGNAL(currentIndexChanged(int)),
	  this, SLOT(computeTimeBase()));

}
void TimeBaseWidget::setSamplerate(int sr)
{
  _samplerate=sr;
  computeTimeBase();
}
int TimeBaseWidget::getBPM()
{
  return _tempo.value();
}
int TimeBaseWidget::getBeatsPerBar()
{
  return _beatsPerBar.value();
}
int TimeBaseWidget::getBeatLength()
{
  return _beatLength.itemData(_beatLength.currentIndex()).toInt();
}
void TimeBaseWidget::computeTimeBase()
{
  int bpm=_tempo.value();
  int bpb=_beatsPerBar.value();
  int beatLength=_beatLength.itemData(_beatLength.currentIndex()).toInt();

  float beat=(float)(4 * bpb) / (float)beatLength;
  float res=((beat * 60.0) / (float)bpm);

  _timeBase=res * _samplerate;
  if (_samplerate) 
    setTitle(tr("Time base - %1 secs (%2 frames @ %3Hz)").arg(res).arg(_timeBase).arg(_samplerate));
  else
    setTitle(tr("Time base - %1 secs").arg(res));
  if (_samplerate)
    emit timeBaseChanged(bpm, bpb, beatLength);
}

// 
// timebase_widget.cpp ends here
