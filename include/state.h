#ifndef STATE_H
#define STATE_H

#include "common.h"

class State {
  public:
    State() = default;
    ~State() = default;

    const EndOrError& finished() { return m_end_reason; }
    const EndOrError& finising() { return m_ending || m_aborting; }
    const EndOrError& ending() { return m_ending; }
    const EndOrError& aborting() { return m_aborting; }
    bool normal() { return !finished() && !finising(); }
    bool ask_end(const EndOrError& end = True) {
      if(finished() || finising()) {
        return false;
      }
      m_ending = end || True;
      return true;
    }
    bool ask_abort(const EndOrError& end = True) {
      if(finished() || m_aborting) {
        return false;
      }
      m_ending = False;
      m_aborting = end || True;
      return true;
    }
    std::string to_string() {
      return "ending: " + std::string(m_ending.what()) +
            ", aborting: " + std::string(m_aborting.what()) +
            ", end_reason: " + std::string(m_end_reason.what());
    }
  private:
    EndOrError m_ending;
    EndOrError m_aborting;
    EndOrError m_end_reason;
};

#endif