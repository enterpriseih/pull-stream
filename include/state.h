#ifndef STATE_H
#define STATE_H

#include "common.h"

class State {
  public:
    State() = default;
    ~State() = default;

    const EndOrError& ending() { return m_ending; }
    const EndOrError& aborting() { return m_aborting; }
    bool ask_end(const EndOrError& end = True) {
      m_ending = end || True;
      return true;
    }
    bool ask_abort(const EndOrError& end = True) {
      m_ending = False;
      m_aborting = end || True;
      return true;
    }
    std::string to_string() {
      return "ending: " + std::string(m_ending.what()) +
            ", aborting: " + std::string(m_aborting.what());
    }
  private:
    EndOrError m_ending;
    EndOrError m_aborting;
};

#endif