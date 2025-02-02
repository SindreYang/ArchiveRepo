// osc.cpp --- 
// 
// Filename: osc.cpp
// Description: 
// Author: stax
// Maintainer: 
// Created: jeu nov 26 17:53:30 2009 (+0100)
// Version: 
// Last-Updated: jeu nov 26 20:28:03 2009 (+0100)
//           By: stax
//     Update #: 9
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

#include <math.h>
#include "osc.h"

Osc::Osc()
{
  _samplerate=0;
  _pos=0;
  _period=0;
  _freq=440;
}
void Osc::setSamplerate(int sr)
{
  _samplerate=sr;
  setFreq(_freq);
}
void Osc::setFreq(float f)
{
  _freq=f;
  if (_samplerate)
    _period=(float)_samplerate / _freq;
}

//
SineOsc::SineOsc() : Osc()
{
  _scale=0;
}
void SineOsc::setFreq(float f)
{
  Osc::setFreq(f);
  if (_samplerate)
    _scale= 2 * PI * _freq / _samplerate;
}
float SineOsc::stepOsc()
{
  float val=sin(_scale * _pos);
  _pos=(_pos + 1) % _period;
  return val;
}

//
SquareOsc::SquareOsc() : Osc()
{
  _halfPeriod=0;
  _val=1.0;
}
void SquareOsc::setFreq(float f)
{
  Osc::setFreq(f);
  if (_samplerate)
    _halfPeriod=_period / 2;
}
float SquareOsc::stepOsc()
{
  if ((_pos % _halfPeriod) == 0)
    _val*=-1;
  _pos=(_pos + 1) % _period;
  return _val;
}

//
TriangleOsc::TriangleOsc() : Osc()
{
  _halfPeriod=0;
  _asc=true;
}
void TriangleOsc::setFreq(float f)
{
  Osc::setFreq(f);
  if (_samplerate)
    _halfPeriod=_period / 2;
  _pos=_period / 4;
}
float TriangleOsc::stepOsc()
{
  float val;
  if (_asc)
    val=(float)(4.0 * _pos) / (float)_period - 1;
  else
    val=(float)(-4.0 * _pos) / (float)_period + 1;
  _pos=(_pos + 1) % _halfPeriod;
  if (_pos == 0)
    _asc=!_asc;
  return val;
}

// 
// osc.cpp ends here
