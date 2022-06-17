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
      return [this](sourceT<Message> source){
        source(false, m_sink_cb);
      };
    };

    void set_id(char id) { m_sink_ID = id; }
    char get_id() const { return m_sink_ID; }


    source_callback<Message> m_sink_cb;
  private:
    char m_sink_ID;
    
};

#endif