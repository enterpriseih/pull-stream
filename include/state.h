#pragma once
#include <assert.h>
#include <exception>
#include <string>

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
    EndOrError operator||(const EndOrError& err) const {
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

class State {
  public:
    State() = default;
    ~State() = default;

    const EndOrError& ending() const { return m_ending; }
    const EndOrError& aborting() const { return m_aborting; }
    const EndOrError& finish() const { return m_finished; }
    bool ask_end(const EndOrError& end = True) {
      m_ending = end || True;
      return true;
    }
    bool ask_abort(const EndOrError& end = True) {
      m_ending = False;
      m_aborting = end || True;
      return true;
    }
    bool ask_finish(const EndOrError& end = True) {
      m_finished = end || True;
      return true;
    }
    void init() {
      m_ending = False;
      m_aborting = False;
      m_finished = False;
    }
    std::string to_string() {
      return "ending: " + std::string(m_ending.what()) +
            ", aborting: " + std::string(m_aborting.what()) +
            ", finished " + std::string(m_finished.what());
    }
  private:
    EndOrError m_ending;
    EndOrError m_aborting;
    EndOrError m_finished;
};
