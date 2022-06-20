#ifndef SOURCE_H
#define SOURCE_H

#include "common.h"

template <typename Message>
class Source {
  public:
    Source(){};
    Source(char id): m_source_ID(id){};
    Source(sourceOptions<Message> source_opts): 
      m_source_ID(source_opts.id), m_source(source_opts.source){};
    sourceT<Message> source() {
      return m_source;
    };

    void set_id(char id) { m_source_ID = id; }
    char get_id() const { return m_source_ID; }
    EndOrError get_end_or_error() const { return m_end_or_error; }
    void set_end_or_error(EndOrError value = False) {
      m_end_or_error = value;
    }
    
    sourceT<Message> m_source;
  private:
    char m_source_ID;
    EndOrError m_end_or_error;
};

#endif