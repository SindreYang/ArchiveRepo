

#ifndef JACK_CLIENT_H
#define JACK_CLIENT_H

#include <QtGui>
#include <QtXml>
#include <jack/jack.h>
#include <jack/ringbuffer.h>
#include <jack/midiport.h>


typedef jack_default_audio_sample_t sample_t;
typedef QMap<QString, jack_port_t*> portmap_t;
typedef QMap<QString, jack_port_t*>::const_iterator portmap_it_t;


struct MidiEvent {
  jack_nframes_t time;
  unsigned char	data[3];
  int size;
};

#define MIDI_NOTE_OFF		0x80
#define MIDI_NOTE_ON		0x90
#define POLYPHONIC_AFTERTOUCH	0xA0
#define MIDI_CONTROLLER		0xB0
#define MIDI_PROGRAM_CHANGE	0xC0
#define MIDI_CHANNEL_AFTERTOUCH	0xD0
#define MIDI_PITCH_BEND_CHANGE	0xE0
#define MIDI_SYSEX		0xF0
#define MIDI_TIME_CODE		0xF1
#define MIDI_SONG_POSITION 	0xF2
#define MIDI_SONG_SELECT	0xF3
// 0xF4 is undefined
// 0xF5 is undefined
#define MIDI_TUNE_REQUEST	0xF6
#define MIDI_SYSEX_END		0xF7
#define MIDI_TIMING_CLOCK	0xF8
// 0xF9 is undefined
#define MIDI_START		0xFA
#define MIDI_CONTINUE		0xFB
#define MIDI_STOP		0xFC
// 0xFD is undefined
#define MIDI_ACTIVE_SENSING	0xFE
#define MIDI_SYSTEM_RESET	0xFF 

#define RINGBUFFER_SIZE	1024 * sizeof(struct MidiEvent)


class JackClient : public QObject
{
Q_OBJECT


protected:
  jack_client_t *_client;
  jack_port_t *_midiInput;
  QString _midiInputName;

  QMap<QString, jack_port_t*> _audioInputs;
  QMap<QString, jack_port_t*> _audioOutputs;
  QMap<QString, jack_port_t*> _midiOutputs;

  QMap<QString, jack_ringbuffer_t*> _ringBuffers;


  QString _name;
  int _midiInputChannel;
  int _midiOutputChannel;
  int _samplerate;
  jack_nframes_t _blockSize;

  virtual void midi_in_process(jack_nframes_t);
  virtual void midi_out_process(jack_nframes_t);
  virtual void audio_process(jack_nframes_t);
  virtual int transportHandler(jack_transport_state_t state, jack_position_t *pos);

public:
  JackClient();
  ~JackClient();


  static int process(jack_nframes_t, void* );
  static void onShutDown(void*);
  static int transportSync(jack_transport_state_t state, jack_position_t *pos, void *arg);

  //
  // client
  //
  bool initClient(QString name);
  virtual void closeClient(bool forced=false);
  bool isActive() {return (_client)?true:false;}
  QString getName(){return _name;}



  //
  // ports
  //
  // creation .deletion
  bool createMidiIn(QString name);
  jack_port_t *addMidiOutput(QString name); 
  jack_port_t *addAudioOutput(QString name); 
  jack_port_t *addAudioInput(QString name); 
  bool removeMidiOutput(QString name); 
  bool removeAudioOutput(QString name); 
  bool removeAudioInput(QString name);
  // retreive ports & connections
  jack_port_t *getPort(QString name);
  QList<QString> getReadablePorts(QString scheme=QString(""));
  QList<QString> getWritablePorts(QString scheme=QString(""));
  QList<QString> getConnections(QString);
  bool connectPorts(const QString &in, const QString &out);
  bool disconnectPorts(const QString &in, const QString &out);
  void connectionsFromXML(QDomElement root);
  QDomElement connectionsToXML();


  // Midi Channel access
  int getInputChannel(){return _midiInputChannel;}
  int getOutputChannel(){return _midiOutputChannel;}
  void sendMidiEvent(QString port, struct MidiEvent);
  void sendMidiMsg(QString port, int channel, int msg, int param1=-1, int param2=-1);


  // samplerate & blocksize
  int getSamplerate() {return _samplerate;}
  jack_nframes_t getBlockSize() {return _blockSize;}

  // transport
  void startTransport();
  void pauseTransport();
  void stopTransport();
  int transportStatus(); 
  int getFramePos();

public slots:
  void setInputChannel(int channel){_midiInputChannel=channel;}
  void setOutputChannel(int channel){_midiOutputChannel=channel;}

signals:
  void receivedMidiEvent(struct MidiEvent);
  void transportChanged(jack_transport_state_t state, jack_position_t *pos);
  void clientStarted();
  void clientStopped();

};



#endif
/* jack_client.h ends here */
