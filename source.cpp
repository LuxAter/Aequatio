#include "aequatio_files/aequatio_headers.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  aequatio::LoadMathFunctions();
  std::cout << aequatio::ListAvalibleFunctions(5) << "\n\n";
  aequatio::Equation f("0");
  std::string good = "";
  while (good != "quit") {
    getline(std::cin, good);
    if (f.ValueString(good)) {
      std::cout << "f(" << good << ")=" << f("x", stod(good)) << "\n";
    } else if (good != "quit") {
      f = good;
      std::cout << f.EquationString() << "\n" << f.EquationString(1) << "\n";
    }
  }
  return 0;
}
