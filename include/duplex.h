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
      m_ID(id) {
      sink_opts.id = sink_opts.id ? sink_opts.id : id;
      sink_opts.sink_cb = sink_opts.sink_cb ? sink_opts.sink_cb : 
        [this](EndOrError end_or_error, T message) {
          // arguments come from source
          // this ptr points to sink's parent: Duplex
          if(end_or_error) {
            std::cout << this->get_id() << "'s peer as Source end or error" << std::endl;
            return; }
          set_received(message);
          std::cout << this->get_id() << 
          " received Message from peer(source): " 
          << message << std::endl;
        };
      source_opts.id = source_opts.id ? source_opts.id : id;
      source_opts.message = message;
      source_opts.source = source_opts.source ? source_opts.source : 
        [this](EndOrError end_or_error, source_callback<T> cb){
          // arguments come from sink
          // this ptr points to source's parent: Duplex
          if(end_or_error) {
            std::cout << this->get_id() << "'s peer as Sink end or error" << std::endl;
            return; }
          this->get_source().source_callback = cb;
          this->get_source().load_buffer();
          drain();
          return;
        };
      m_sink = Sink<T>(sink_opts);
      m_source = Source<T>(source_opts);
    };

    void drain() {
      std::queue<T> &buf = get_buffer();
      while (!buf.empty())
      {
        T tmp = buf.front();
        buf.pop();
        get_source().source_callback(get_source().get_end_or_error(), tmp);
      }
    }

    Source<T>& get_source() { return m_source; }
    Sink<T>& get_sink() { return m_sink; }

    void set_id(char id) { m_ID = id; }
    char get_id() const { return m_ID; }

    T get_message() const { return m_source.get_message(); }
    T get_received() const { return m_sink.get_received(); }
    void set_received(T m) { m_sink.set_received(m); }
    void set_message(T m) { 
      m_source.set_message(m);
      m_source.load_buffer();
      drain();
    }
    
    std::queue<T>& get_buffer() { return m_source.get_buffer(); }
  private:
    Source<T> m_source;
    Sink<T> m_sink;

    char m_ID;
};

// void end_source() { m_source.set_end_or_error(true, false); }
// void end_sink() { m_sink.set_end_or_error(true, false); }
// void end() { 
//   end_source();
//   end_sink();
// }

// void abort_source() {}
// void abort_sink() {}
// void abort() {
//   abort_source();
//   abort_sink();
// }

#endif