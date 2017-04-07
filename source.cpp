#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

int main(int argc, char const* argv[]) {
  Equation eq("3 + 4 * 2 / ( 1 - x ) ^ 2 ^ 3");
  eq.Parse(SHUNTING_YARD);
  std::cout << eq.String(E_INFIX) << "\n";
  std::cout << eq.String(E_RPN) << "\n";
  eq.SetVariables(std::map<std::string, Symbol>{std::make_pair("x", 5)});
  std::cout << "=" << eq().val_double << "\n";
  return 0;
}
