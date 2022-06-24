#ifndef DUPLEX_H
#define DUPLEX_H

#include "common.h"

template<typename T> 
class Duplex {
  public:
    Duplex(){};

    Duplex(const char& id, const T& message,
      sinkOptions<T> sink_opts = sinkOptions<T>{},
      sourceOptions<T> source_opts = sourceOptions<T>{}): 
      m_ID(id) {
      sink_opts.id = sink_opts.id ? sink_opts.id : id;
      sink_opts.sink_cb = sink_opts.sink_cb ? sink_opts.sink_cb : 
        [this](const State& source_state, const T& message) {
          // arguments come from source
          // this ptr points to sink's parent: Duplex
          if(source_state.finish()) {
            std::cout << this->get_id() << "'s peer as Source end or error" << std::endl;
            return; }
          this->set_received(message);
          std::cout << this->get_id() << 
          " received Message from peer(source): " 
          << message << std::endl;
        };
      source_opts.id = source_opts.id ? source_opts.id : id;
      source_opts.message = message;
      source_opts.source = source_opts.source ? source_opts.source : 
        [this](const State& sink_state, const source_callback<T>& cb){
          // arguments come from sink
          // this ptr points to source's parent: Duplex
          sink_state_handler(sink_state);
          if(sink_state.finish()) {
            std::cout << this->get_id() << "'s peer as Sink end or error" << std::endl;
            return; }
          this->get_source().source_callback = cb;
          this->drain();
          return;
        };
      m_sink = Sink<T>(sink_opts);
      m_source = Source<T>(source_opts);
    };

    void sink_state_handler(const State& sink_state) {
      m_source.set_peer_state(sink_state);
      if(sink_state.aborting()) {
        while (!m_source.get_buffer().empty())
          m_source.get_buffer().pop();
        std::cout << "buffer cleared!" << std::endl;
        m_source.get_peer_state().ask_finish();
      }
      if(sink_state.ending()) {
        m_source.get_peer_state().ask_finish();
      }
    }
    void drain() {
      if(m_source.get_state().finish()) return;
      if(m_source.get_state().aborting() || m_source.get_state().ending()) {
        m_source.get_state().ask_finish();
        return;
      }
      if(!m_source.get_peer_state().finish())
        drain_buffer();
    }

    void drain_buffer() {
      std::queue<T> &buf = m_source.get_buffer();
      while (!buf.empty())
      {
        T tmp = buf.front();
        buf.pop();
        m_source.source_callback(m_source.get_state(), tmp);
      }
    }

    void abort_source() { 
      m_source.get_state().ask_abort(); 
      while (!m_source.get_buffer().empty())
        m_source.get_buffer().pop();
        std::cout << "buffer cleared!" << std::endl;
    }

    void end_source() { 
      m_source.get_state().ask_end();
    }
    
    void abort_sink() { 
      m_sink.get_state().ask_abort(); 
      if(m_sink.m_peer_source) m_sink.m_peer_source(m_sink.get_state(), m_sink.m_sink_cb);
    }
    void end_sink() { 
      m_sink.get_state().ask_end(); 
      if(m_sink.m_peer_source) m_sink.m_peer_source(m_sink.get_state(), m_sink.m_sink_cb);
    }


    void abort() {
      abort_sink();
      abort_source();
    }
    void end() {
      end_sink();
      end_source();
    }
    void init() {
      m_sink.get_state().init();
      m_source.get_state().init();
    }
    Source<T>& get_source() { return m_source; }
    Sink<T>& get_sink() { return m_sink; }

    void set_id(const char& id) { m_ID = id; }
    const char& get_id() const { return m_ID; }

    const T& get_message() const { return m_source.get_message(); }
    const T& get_received() const { return m_sink.get_received(); }
    void set_received(const T& m) { m_sink.set_received(m); }
    void set_message(const T m) { 
      m_source.set_message(m);
      m_source.load_buffer();
      drain();
    }
    
    const std::queue<T>& get_buffer() { return m_source.get_buffer(); }
  private:
    Source<T> m_source;
    Sink<T> m_sink;
    char m_ID;
};


#endif