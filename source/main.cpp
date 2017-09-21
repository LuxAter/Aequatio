#include "lexer/token.hpp"

#include <iostream>

int main(int argc, char const* argv[]) {
  aequatio::lexer::Token t(true), b(0.00512);
  if (t == b) {
    std::cout << "t == b\n";
  }
  aequatio::lexer::Token v = (t + b);
  std::cout << t << "," << b << "\n";
  std::cout << "v:" << v << "\n";
  return 0;
}
