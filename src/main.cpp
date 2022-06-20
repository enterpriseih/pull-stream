#include "../include/common.h"


int main() {
  Duplex<int> a('A', random());
  std::cout << "a.get_message: " << a.get_message() << std::endl;

  Duplex<int> b('B', random());
  std::cout << "b.get_message: " << b.get_message() << std::endl;
  
  link(a, b);

  Duplex<std::string> c('C', "I am C");
  std::cout << "c.get_message: " << c.get_message() << std::endl;
  // c.get_sink().set_end_or_error(True);
  c.get_source().set_end_or_error(True);

  Duplex<std::string> d('D', "I am D");
  std::cout << "d.get_message: " << d.get_message() << std::endl;
  d.get_source().set_end_or_error(True);
  link(c, d);

}