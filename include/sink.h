#ifndef SINK_H
#define SINK_H

#include "common.h"

template<typename Message>
class Sink {
  public:
    Sink(){};
    Sink(char id): m_sink_ID(id){};
    Sink(sinkOptions<Message> sink_opts): 
      m_sink_ID(sink_opts.id), m_sink_cb(sink_opts.sink_cb) {};

    sinkT<Message> sink() {
      if(m_state.aborting()) {
        m_state.ask_end();
        m_end_or_error = True;
      }
      return [this](sourceT<Message> source) {
        m_peer_source = source;
        source(this->m_end_or_error, this->m_sink_cb);
      };
    };
    State& get_state() { return m_state; }
    void set_id(char id) { m_sink_ID = id; }
    char get_id() const { return m_sink_ID; }

    EndOrError get_end_or_error() const { return m_end_or_error; }
    void set_end_or_error(EndOrError value = False) {
      m_end_or_error = value;
    }
    Message get_received() const { return m_received; }
    void set_received(Message m) { m_received = m; }
    sourceT<Message> m_peer_source;
    source_callback<Message> m_sink_cb;
  private:
    char m_sink_ID;
    EndOrError m_end_or_error;
    Message m_received;
    State m_state;
};

#endif