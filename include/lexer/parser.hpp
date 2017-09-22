#ifndef AEQUATIO_LEXER_PARSER_HPP
#define AEQUATIO_LEXER_PARSER_HPP

#include <string>

#include "lexer.hpp"
#include "token.hpp"

namespace aequatio::lexer {
  class Parser {
   public:
    Parser();
    Parser(Lexer lexer);
    Parser(const Parser& copy);

    Token Expr();

   private:
    void Error();
    void Eat(Token::Type type);
    Token Factor();

    Lexer lexer_;
    Token current_token_;
  };
}  // namespace aequatio::lexer

#endif /* ifndef AEQUATIO_LEXER_PARSER_HPP */
