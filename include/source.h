#ifndef SOURCE_H
#define SOURCE_H

#include "common.h"
#include <queue>

template <typename Message>
class Source {
  public:
    Source(){};
    Source(char id): m_source_ID(id){};
    Source(sourceOptions<Message> source_opts): 
      m_source_ID(source_opts.id), 
      m_message(source_opts.message),
      m_source(source_opts.source){};

    sourceT<Message> source() { return m_source; };

    std::queue<Message>& get_buffer() { return m_buffer; }
    
    std::queue<Message> load_buffer() {
      m_buffer.push(m_message);
      return m_buffer;
    }

    void set_id(const char& id) { m_source_ID = id; }
    const char get_id() const { return m_source_ID; }
    const EndOrError get_end_or_error() const { return m_end_or_error; }
    void set_end_or_error(const EndOrError& value = False) {
      m_end_or_error = value;
    }
    const Message get_message() const { return m_message; }
    void set_message(const Message& m) { 
      m_message = m;
    }
    State& get_state() { return m_state; }

    sourceT<Message> m_source;
    source_callback<Message> source_callback; 
  private:
    char m_source_ID;
    EndOrError m_end_or_error;
    Message m_message;
    std::queue<Message> m_buffer;
    State m_state;
};

#endif