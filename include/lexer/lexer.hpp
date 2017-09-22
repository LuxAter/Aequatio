#ifndef AEQUATIO_LEXER_LEXER_HPP
#define AEQUATIO_LEXER_LEXER_HPP

#include <string>

#include "token.hpp"

namespace aequatio::lexer {
  class Lexer {
   public:
    Lexer();
    Lexer(std::string text);
    Lexer(const Lexer& copy);

    Token GetNextToken();

   private:
    void Error();
    void Advance();
    void SkipWhitespace();
    Token Integer();

    std::string text_;
    char current_char_;
    unsigned int index_;
  };
}  // namespace aequatio::lexer

#endif /* ifndef AEQUATIO_LEXER_LEXER_HPP */
