#pragma once
#include <assert.h>
#include <exception>
#include <string>


class State {
  public:
    State() = default;
    explicit State(bool end): m_end(end) {}
    bool finish() const {
      return m_end;
    }
    void init() {
      m_end = false;
    }
  private:
    bool m_end = false;
};