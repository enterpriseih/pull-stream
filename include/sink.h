#ifndef SINK_H
#define SINK_H

#include "common.h"

template<typename Message>
class Sink {
  public:
    Sink(){};
    Sink(const char& id): m_sink_ID(id){};
    Sink(const sinkOptions<Message>& sink_opts): 
      m_sink_ID(sink_opts.id), m_sink_cb(sink_opts.sink_cb) {};

    sinkT<Message> sink() {
      return [this](const sourceT<Message>& source) {
        m_peer_source = source;
        source(this->m_state, this->m_sink_cb);
      };
    };
    State& get_state() { return m_state; }
    void set_id(const char& id) { m_sink_ID = id; }
    const char& get_id() const { return m_sink_ID; }

    const Message& get_received() const { return m_received; }
    void set_received(const Message& m) { m_received = m; }
    sourceT<Message> m_peer_source;
    source_callback<Message> m_sink_cb;
  private:
    char m_sink_ID;
    Message m_received;
    State m_state;
};

#endif