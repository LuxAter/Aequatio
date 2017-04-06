#include <iostream>
#include "src/equation/equation.hpp"

int main(int argc, char const* argv[]) {
  aequatio::Equation eq("6 * ( 8 * 3 - 4 ) - 3");
  std::cout << eq.String() << "->" << eq.RpnString() << "\n";
  std::cout << "=" << eq() << "\n";
  return 0;
}
