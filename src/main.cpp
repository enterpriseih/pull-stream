#include "../include/common.h"


int main() {
  std::string message_A = "A@1";
  std::string message_B = "B@1";
  Duplex<std::string> a('A', message_A);
  Duplex<std::string> b('B', message_B);
  a.end_sink();
  link(a, b);
  // std::cout << "a.get_received() = " << a.get_received() << std::endl;
  // std::cout << "b.get_received() = " << b.get_received() << std::endl;
  std::string message_A_1 = "A@2";
  a.set_message(message_A_1);
  // std::cout << "a.get_message() = " << a.get_message() << std::endl;
  std::string message_B_1 = "B@2";
  b.set_message(message_A_1);
  // std::cout << "a.get_received() = " << a.get_received() << std::endl;
  // std::cout << "b.get_received() = " << b.get_received() << std::endl;
}
