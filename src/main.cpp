#include "../include/common.h"


int main() {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  // b.end_source();
  // b.abort_source();
  // a.get_sink().get_state().ask_abort();
  // a.get_sink().get_state().ask_end();
  // a.abort_sink();
  a.end_sink();
  link(a, b);
  // a.end_sink();
  // a.abort_sink();
  // b.end_source();
  // a.get_sink().get_state().ask_abort();
  // a.get_sink().get_state().ask_end();

  // a.get_sink().m_peer_source(a.get_sink().get_state(), a.get_sink().m_sink_cb);
  b.set_message("B@2");
  b.set_message("B@3");
  b.set_message("B@4");
  // reconnect(a, b);
}
