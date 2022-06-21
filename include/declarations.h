#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include <functional>
#include <assert.h>
#include <exception>
#include <string>
// struct EndOrError
// {
//   bool end = false;
//   bool error = false;
// };

class EndOrError : std::exception {
  public:
    explicit EndOrError(bool value = false) noexcept :
      m_tag(END), m_end(value) {}
    explicit EndOrError(const char* msg) noexcept : m_tag(ERROR) {
      assert(msg);
      m_error = msg;
    }
    explicit EndOrError(const std::string& msg) noexcept :
      EndOrError(msg.c_str()) {}
    explicit operator bool() const { return ERROR == m_tag || m_end; }
    EndOrError operator||(const EndOrError err) const {
      return (*this) ? *this : err;
    }
    bool operator==(const EndOrError& err) const {
      if(this->m_tag != err.m_tag) return false;
      if(this->m_tag == END) return this->m_end == err.m_end;
      return m_error == err.m_error;
    }
    bool operator!=(const EndOrError& err) const {
      return !((*this) == err);
    }
    bool is_end() const { return END == m_tag && m_end; }
    bool is_error() const { return ERROR == m_tag; } 
    const char* what() const noexcept override {
      if (m_tag == END) {
        return m_end ? "true" : "false";
      } else {
        return m_error.c_str();
      }
    }
    template <typename OStream>
    friend OStream& operator<<(OStream& os, const EndOrError& v) {
      return os << v.what();
  }

  private:
    enum { END, ERROR } m_tag;
    bool m_end;
    std::string m_error;
};
const EndOrError True = EndOrError{true};
const EndOrError False = EndOrError{false};

template <class T>
using source_callback = std::function<void (EndOrError, T)>;
template <class T>
using sourceT = std::function<void (EndOrError, source_callback<T>)>;
template <class T>
using sinkT = std::function<void (sourceT<T>)>;

template<typename T> 
struct sinkOptions {
  char id;
  source_callback<T> sink_cb = nullptr;
};

template<typename T> 
struct sourceOptions {
  char id;
  sourceT<T> source = nullptr;
  T message;
};


#endif