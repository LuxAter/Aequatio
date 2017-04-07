#include <iostream>
#include "src/equation/equation.hpp"

using namespace aequatio;

int main(int argc, char const* argv[]) {
  Equation eq("( ( 1 + 2 ) ^ ( 3 + 4 ) ) ^ ( 5 + 6 )");
  eq.Parse(SHUNTING_YARD);
  std::cout << eq.String(E_INFIX) << "\n";
  std::cout << eq.String(E_RPN) << "\n";
  return 0;
}
