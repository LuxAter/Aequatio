#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

int main(int argc, char const* argv[]) {
  Symbol* sy = new Number(3.1415);
  Number* num = dynamic_cast<Number*>(sy);
  std::cout << (*num)() << "\n";
  return 0;
}
