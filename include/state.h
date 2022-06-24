#ifndef STATE_H
#define STATE_H

#include "common.h"

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

#endif