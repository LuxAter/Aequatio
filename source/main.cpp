#include "lexer/lexer.hpp"
#include "lexer/parser.hpp"
#include "lexer/token.hpp"

#include <iostream>

int main(int argc, char const* argv[]) {
  std::string input;
  while (true) {
    std::cout << "calc>";
    getline(std::cin, input);
    try {
      aequatio::lexer::Lexer lex(input);
      aequatio::lexer::Parser parser(lex);
      aequatio::lexer::Token result = parser.Expr();
      std::cout << result << "\n";
    } catch (const char* msg) {
      std::cerr << msg << std::endl;
    }
  }
  return 0;
}
