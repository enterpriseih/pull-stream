#ifndef DUPLEX_H
#define DUPLEX_H

#include "common.h"

template<typename T> 
class Duplex {
  public:
    Duplex(){};

    Duplex(char id, T message,
      sinkOptions<T> sink_opts = sinkOptions<T>{},
      sourceOptions<T> source_opts = sourceOptions<T>{}): 
      m_message(message), m_ID(id) {
      sink_opts.id = sink_opts.id ? sink_opts.id : id;
      sink_opts.sink_cb = sink_opts.sink_cb ? sink_opts.sink_cb : 
        [this](bool end, T message) {
          std::cout << this->get_id() << 
          " received Message from peer(source): " 
          << message << std::endl;
        };
      source_opts.id = source_opts.id ? source_opts.id : id;
      source_opts.source = source_opts.source ? source_opts.source : 
        [this](bool end, source_callback<T> cb){
          return cb(end, this->get_message());
        };
      m_sink = Sink<T>(sink_opts);
      m_source = Source<T>(source_opts);
    };

    Source<T>& get_source() { return m_source; }
    Sink<T>& get_sink() { return m_sink; }

    void set_id(char id) { m_ID = id; }
    char get_id() const { return m_ID; }

    T get_message() const { return m_message; }
  private:
    Source<T> m_source;
    Sink<T> m_sink;
    T m_message;
    char m_ID;
};

#endif