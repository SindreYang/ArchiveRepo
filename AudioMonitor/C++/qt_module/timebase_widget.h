/* timebase_widget.h --- 
 * 
 * Filename: timebase_widget.h
 * Description: 
 * Author: stax
 * Maintainer: 
 * Created: ven nov 27 17:00:30 2009 (+0100)
 * Version: 
 * Last-Updated: ven nov 27 19:03:53 2009 (+0100)
 *           By: stax
 *     Update #: 8
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

#ifndef TIMEBASE_WIDGET_H
#define TIMEBASE_WIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <QLabel>
class TimeBaseWidget : public QGroupBox
{
 Q_OBJECT
 private:
  int _samplerate;
  int _timeBase;
  QSpinBox _tempo;
  QSpinBox _beatsPerBar;
  QComboBox _beatLength;

 private slots:
  void computeTimeBase();

 public:
  TimeBaseWidget();
  
  void setSamplerate(int sr);
  int getBPM();
  int getBeatsPerBar();
  int getBeatLength();
  int getTimeBase() {return _timeBase;}

 signals:
  void timeBaseChanged(int bpm, int beats_per_bar, int beat_length);

};

#endif

/* timebase_widget.h ends here */
