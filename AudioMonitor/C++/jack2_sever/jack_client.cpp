
#include <math.h>
#include "jack_client.h"

JackClient::JackClient()
{
  _client=NULL;
  _midiInput=NULL;
  _midiInputChannel=-1;
  _midiOutputChannel=-1;
  _samplerate=0;
  _blockSize=0;

  qRegisterMetaType<MidiEvent>("MidiEvent");
  qRegisterMetaType<jack_position_t>("jack_position_t");
  qRegisterMetaType<jack_transport_state_t>("jack_transport_state_t");
}
JackClient::~JackClient()
{
  qDebug() << "[JackClient] clean";
  closeClient();
}

bool JackClient::initClient(QString name)
{
  _name=name;
  qDebug() << "[JackClient]"<<_name<<"init...";

  _client=jack_client_open(_name.toStdString().c_str(), JackNullOption, NULL);
  if (_client == NULL) {
    qWarning("[JackClient] Cannot create JACK client");
    return false;
  }

  jack_set_sync_callback(_client, JackClient::transportSync, this);
  jack_set_process_callback(_client, JackClient::process, this);
  jack_on_shutdown(_client, JackClient::onShutDown, this);
 
  _blockSize=jack_get_buffer_size(_client);
  _samplerate=jack_get_sample_rate(_client);

  qDebug() << "[JackClient] activating ...";
  if (jack_activate(_client)) {
    closeClient();
    qWarning("[JackClient] Cannot activate JACK client.");
    return false;
  }
  qDebug() << "[JackClient] init done.";
  return true;
}
void JackClient::closeClient(bool forced)
{
  if (!forced && _client) {
    if (!::jack_deactivate(_client))
      ::jack_client_close(_client);
  }  
  _client=NULL;
  if (_midiInput) {
    _midiInput=NULL;
  }
  _audioInputs.clear();
  _audioOutputs.clear();
  _midiOutputs.clear();
  foreach (jack_ringbuffer_t *rb, _ringBuffers)
    jack_ringbuffer_free(rb);
  _ringBuffers.clear();

  emit clientStopped();
}

bool JackClient::createMidiIn(QString name) 
{
  if (_client) {
    //qDebug() << "JackBackend::midiin()";
    _midiInputName=name;
    _midiInput=jack_port_register(_client, name.toStdString().c_str(), JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
    if (_midiInput)
      return true;
  }
  return false;
}
jack_port_t *JackClient::addMidiOutput(QString name) 
{
  jack_port_t *port;
  if (_client) {
    if (_midiOutputs.contains(name))
      return NULL;
    //qDebug() << "JackBackend::addOutput(" << name << ")";
    port=jack_port_register(_client, name.toStdString().c_str(), JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);
    _midiOutputs.insert(name, port);

    jack_ringbuffer_t *rb;
    rb=jack_ringbuffer_create(RINGBUFFER_SIZE);
    if (rb == NULL) {
      jack_port_unregister(_client, port);
      _midiOutputs.remove(name);
      qWarning("Cannot create JACK ringbuffer.");
      return NULL;
    }
    jack_ringbuffer_mlock(rb);
    _ringBuffers.insert(name, rb);

    return port;
  }
  return NULL;
}
jack_port_t *JackClient::addAudioOutput(QString name) 
{
  jack_port_t *port;
  if (_client) {
    if (_audioOutputs.contains(name))
      return NULL;
    //qDebug() << "JackBackend::addOutput(" << name << ")";
    port=jack_port_register(_client, name.toStdString().c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    _audioOutputs.insert(name, port);
    return port;
  }
  return NULL;
}
jack_port_t *JackClient::addAudioInput(QString name) 
{
  jack_port_t *port;
  if (_client) {
    if (_audioInputs.contains(name))
      return NULL;
    //qDebug() << "JackBackend::addInput(" << name << ")";
    port=jack_port_register(_client, name.toStdString().c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    _audioInputs.insert(name,  port);
    return port;
  }
  return NULL;
}
bool JackClient::removeMidiOutput(QString name) 
{
  //qDebug() << "JackBackend::removeOutput(" << name << ")";
  if (_client && (_midiOutputs.find(name) != _midiOutputs.end()))
    jack_port_unregister(_client, _midiOutputs[name] );
  _midiOutputs.remove(name);
  jack_ringbuffer_free(_ringBuffers[name]);
  _ringBuffers.remove(name);
  return true;
}
bool JackClient::removeAudioOutput(QString name) 
{
  //qDebug() << "JackBackend::removeOutput(" << name << ")";
  if (_client && (_audioOutputs.find(name) != _audioOutputs.end()))
    jack_port_unregister(_client, _audioOutputs[name] );
  _audioOutputs.remove(name);
  return true;
}
bool JackClient::removeAudioInput(QString name) 
{
  //qDebug() << "JackBackend::removeInput(" << name << ")";
  if (_client && (_audioInputs.find(name) != _audioInputs.end()))
    jack_port_unregister(_client, _audioInputs[name]);
  _audioInputs.remove(name);
  return true;
}
QList<QString> JackClient::getReadablePorts(QString nameScheme)
{
  const char **ports;
  QList<QString> res;

  if (!_client)
    return res;

  QRegExp re(nameScheme);
  re.setPatternSyntax(QRegExp::Wildcard);
  if (!re.isValid())
    qDebug()<<"[JackClient] invalid regexp:"<<re.errorString();
  ports=jack_get_ports(_client, NULL, JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput);

  for (int i=0; ports[i]; i++) {
    if (nameScheme.isEmpty() || re.exactMatch(ports[i]))
      res<<ports[i];
  }
  free(ports);
  return res;
}

QList<QString> JackClient::getWritablePorts(QString nameScheme)
{
  const char **ports;
  QList<QString> res;

  if (!_client)
    return res;

  QRegExp re(nameScheme);
  re.setPatternSyntax(QRegExp::Wildcard);
  if (!re.isValid())
    qDebug()<<"[JackClient] invalid regexp:"<<re.errorString();
  ports=jack_get_ports(_client, NULL, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput);

  for (int i=0; ports[i]; i++) {
    if (nameScheme.isEmpty() || re.exactMatch(ports[i]))
      res<<ports[i];
  }
  free(ports);
  return res;
}

QList<QString> JackClient::getConnections(QString from)
{
  const char **connections;
  QList<QString> res;

  if (!_client)
    return res;

  jack_port_t *port=jack_port_by_name(_client, from.toLatin1());
  if ((connections=jack_port_get_all_connections(_client, port)) != 0) {
    for (int i=0; connections[i]; i++) {
      res<<connections[i];
    }
    free (connections);
  } 
  return res;
}

bool JackClient::connectPorts(const QString &in, const QString &out)
{
  if (!_client)
    return false;

  jack_port_t *input_port;
  jack_port_t *output_port;

  if ((input_port=jack_port_by_name(_client, in.toLatin1())) == 0) {
    qDebug()<<"[JackClient] ERROR "<<in<<" not a valid port";
    return 1;
  }
  if ((output_port=jack_port_by_name(_client, out.toLatin1())) == 0) {
    qDebug()<<"[JackClient] ERROR "<<out<<" not a valid port\n";
    return 1;
  }

  if (jack_connect(_client, jack_port_name(input_port), jack_port_name(output_port))) {
    qDebug()<<"[JackClient] cannot connect ports";
    return false;
  }
  return true;
}

bool JackClient::disconnectPorts(const QString &in, const QString &out){
    if (!_client)
        return false;

    jack_port_t *input_port;
    jack_port_t *output_port;

    if ((input_port=jack_port_by_name(_client, in.toLatin1())) == 0) {
        qDebug()<<"[JackClient] ERROR "<<in<<" not a valid port";
        return 1;
    }
    if ((output_port=jack_port_by_name(_client, out.toLatin1())) == 0) {
        qDebug()<<"[JackClient] ERROR "<<out<<" not a valid port\n";
        return 1;
    }

    if (jack_disconnect(_client, jack_port_name(input_port), jack_port_name(output_port))) {
        qDebug()<<"[JackClient] 无法断开端口链接";
        return false;
    }
    return true;


}
jack_port_t *JackClient::getPort(QString name) 
{
  if (!_client)
    return NULL;

  return jack_port_by_name(_client, name.toLatin1());
}
void JackClient::connectionsFromXML(QDomElement root)
{
  uint i;
  portmap_it_t it;
  QDomElement elt;
  QDomNodeList cons;

  cons=root.elementsByTagName("jack_connections");
  if (cons.length())
    root=cons.item(0).toElement();
  else
    return;

  if (_midiInput) {
    cons=root.elementsByTagName(_midiInputName);
    for (i=0; i < cons.length(); i++) {
      elt=cons.item(i).toElement();
      connectPorts(elt.attribute("input"), _name + ":" + _midiInputName);
    }
  }
  it=_midiOutputs.constBegin();
  while (it != _midiOutputs.constEnd()) {
    cons=root.elementsByTagName(it.key());
    for (i=0; i < cons.length(); i++) {
      elt=cons.item(i).toElement();
      connectPorts(_name + ":" + it.key(), elt.attribute("output"));
    }
    it++;
  }

  it=_audioOutputs.constBegin();
  while (it != _audioOutputs.constEnd()) {
    cons=root.elementsByTagName(it.key());
    for (i=0; i < cons.length(); i++) {
      elt=cons.item(i).toElement();
      connectPorts(_name + ":" + it.key(), elt.attribute("output"));
    }
    it++;
  }

  it=_audioInputs.constBegin();
  while (it != _audioInputs.constEnd()) {
    cons=root.elementsByTagName(it.key());
    for (i=0; i < cons.length(); i++) {
      elt=cons.item(i).toElement();
      connectPorts(elt.attribute("input"), _name + ":" + it.key());
    }
    it++;
  }
}
QDomElement JackClient::connectionsToXML()
{
  QDomDocument conf;
  QDomElement root, cnx;
  int i;
  portmap_it_t it;

  root=conf.createElement("jack_connections");

  QStringList cons;
  if (_midiInput) {
    cons=getConnections(_name + ":" + _midiInputName);
    for (i=0; i < cons.count(); i++) {
      cnx=conf.createElement(_midiInputName);
      cnx.setAttribute("input", cons.at(i));
      root.appendChild(cnx);
    }
  }
  it=_midiOutputs.constBegin();
  while (it != _midiOutputs.constEnd()) {
    cons=getConnections(_name +":" + it.key());
    for (i=0; i < cons.count(); i++) {
      cnx=conf.createElement(it.key());
      cnx.setAttribute("output", cons.at(i));
      root.appendChild(cnx);
    }
    it++;
  }

  it=_audioOutputs.constBegin();
  while (it != _audioOutputs.constEnd()) {
    cons=getConnections(_name +":" + it.key());
    for (i=0; i < cons.count(); i++) {
      cnx=conf.createElement(it.key());
      cnx.setAttribute("output", cons.at(i));
      root.appendChild(cnx);
    }
    it++;
  }

  it=_audioInputs.constBegin();
  while (it != _audioInputs.constEnd()) {
    cons=getConnections(_name +":" + it.key());
    for (i=0; i < cons.count(); i++) {
      cnx=conf.createElement(it.key());
      cnx.setAttribute("input", cons.at(i));
      root.appendChild(cnx);
    }
    it++;
  }


  return root;
}
void JackClient::sendMidiMsg(QString port, int channel, int msg, int param1, int param2)
{
  if (!_client)
    return;
  struct MidiEvent ev;
  ev.size=1;
  if (msg >= 0x80 && msg <= 0xEF) {
    msg &= 0xF0;
    if (channel == -1)
      msg += _midiOutputChannel;
    else
      msg += channel;
  }
  ev.data[0]=msg;
  if (param1 != -1) {
    ev.size++;
    ev.data[1]=param1;
    if (param2 !=-1) {
      ev.size++;
      ev.data[2]=param2;
    }
  }
  sendMidiEvent(port, ev);
}

void JackClient::sendMidiEvent(QString port, struct MidiEvent ev)
{
  if (!_client)
    return;
  ev.time=jack_frame_time(_client);
  int n=jack_ringbuffer_write(_ringBuffers[port], (char *)&ev, sizeof(ev));
  if (n != sizeof(ev))
    qWarning()<<"Not enough space in the ringbuffer, NOTE LOST.";
  //qDebug()<<"writing "<<ev.time<<" "<<ev.data[0]<<" "<<ev.data[1]<<" "<<ev.data[2]<<" =>"<<ev.size;
}


void JackClient::startTransport()
{
  if (_client)
    jack_transport_start(_client);
}
void JackClient::pauseTransport()
{
  if (_client)
    jack_transport_stop(_client);
}
void JackClient::stopTransport()
{
  if (_client) {
    jack_transport_stop(_client);
    jack_transport_locate(_client, 0);
  }
}
int JackClient::transportStatus()
{
  jack_position_t pos;
  
  if (_client)
    return jack_transport_query(_client, &pos);
  return 0;
}
int JackClient::getFramePos()
{
  jack_position_t pos;
  
  if (_client) {
    jack_transport_query(_client, &pos);
    return pos.frame;
  }
  return 0;
}

void JackClient::midi_out_process(jack_nframes_t nframes)
{
  portmap_it_t i=_midiOutputs.constBegin();
  while (i != _midiOutputs.constEnd()) {
    struct MidiEvent ev;
    int read, t;
    unsigned char* buffer ;
    jack_nframes_t last_frame_time=jack_last_frame_time(_client);
    void *port_buf=jack_port_get_buffer(i.value(), nframes);
    jack_ringbuffer_t *rb=_ringBuffers[i.key()];

    jack_midi_clear_buffer(port_buf);
    while (jack_ringbuffer_read_space(rb)) {
      read=jack_ringbuffer_peek(rb, (char *)&ev, sizeof(ev));
      if (read != sizeof(ev)) {
	qWarning()<<" Short read from the ringbuffer, possible note loss.";
	jack_ringbuffer_read_advance(rb, read);
	continue;
      }
      else {
	t=ev.time + nframes - last_frame_time;
	if (t >= (int)nframes)
	  break;
	if (t < 0)
	  t=0;
	jack_ringbuffer_read_advance(rb, sizeof(ev));
	buffer=jack_midi_event_reserve(port_buf, t, ev.size);
	if (buffer != NULL)
	  memcpy(buffer, ev.data, ev.size);
      }
    }
    i++;
  }
}
void JackClient::midi_in_process(jack_nframes_t nframes)
{
  if (!_midiInput)
    return;

  struct MidiEvent ev;
  int read, events, i;  
  jack_midi_event_t event;
  void *port_buf=jack_port_get_buffer(_midiInput, nframes);

  if (port_buf == NULL) {
    qWarning()<<"[JackClient] jack_port_get_buffer failed, cannot receive anything.";
    return;
  }

  events=jack_midi_get_event_count(port_buf);
  
  for (i = 0; i < events; i++) {
    read=jack_midi_event_get(&event, port_buf, i);
    if (read) {
      qWarning()<<"[JackClient] jack_midi_event_get failed, RECEIVED NOTE LOST.";
      continue;
    }
    
    if (event.size > 3) {
      qWarning()<<"[JackClient] Ignoring MIDI message longer than three bytes, probably a SysEx."<<event.size;
      continue;
    }
    if ((_midiInputChannel == -1) ||
	((_midiInputChannel != -1) && (_midiInputChannel == (event.buffer[0] & 0x0F)))) {
      ev.time=event.time;
      ev.size=event.size;
      memcpy(ev.data, event.buffer, event.size);
      emit receivedMidiEvent(ev);
    }
  }
}
void JackClient::audio_process(jack_nframes_t)
{
}
int JackClient::transportHandler(jack_transport_state_t state, jack_position_t *pos)
{
  emit transportChanged(state, pos);
  return 1;
}



int JackClient::process(jack_nframes_t nframes, void *arg)
{
  JackClient* jm=static_cast<JackClient*>( arg );

  jm->midi_out_process(nframes);
  jm->midi_in_process(nframes);
  jm->audio_process(nframes);
  
  return 0;
}
void JackClient::onShutDown(void* arg ) 
{
  JackClient* jm=static_cast<JackClient*>( arg );
  jm->closeClient(true);
}
int JackClient::transportSync(jack_transport_state_t state, jack_position_t *pos, void *arg)
{
  JackClient* jm=static_cast<JackClient*>( arg );

  return jm->transportHandler(state, pos);
}
// 
// jack_client.cpp ends here
