#include "../include/common.h"


int main() {
  Duplex<int> a('A', 1);
  std::cout << "a.get_message: " << a.get_message() << std::endl;

  Duplex<int> b('B', 2);
  std::cout << "b.get_message: " << b.get_message() << std::endl;
  
  link(a, b);

  
  link(a, b);
}
