#include "../include/duplex.h"


int main() {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a("A", message_A);
  Duplex<std::string> b("B", message_B);
  link(a, b);
}
