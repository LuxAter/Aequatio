#include "lexer/parser.hpp"

#include <string>

#include "lexer/lexer.hpp"
#include "lexer/token.hpp"

aequatio::lexer::Parser::Parser() {}

aequatio::lexer::Parser::Parser(Lexer lexer) : lexer_(lexer) {
  current_token_ = lexer_.GetNextToken();
}

aequatio::lexer::Parser::Parser(const Parser& copy)
    : lexer_(copy.lexer_), current_token_(copy.current_token_) {}

aequatio::lexer::Token aequatio::lexer::Parser::Expr() {
  Token result = Factor();
  while (current_token_.type == Token::MUL ||
         current_token_.type == Token::DIV) {
    Token token = current_token_;
    if (token.type == Token::MUL) {
      Eat(Token::MUL);
      std::cout << result << "*=" << current_token_ << "\n";
      result *= Factor();
    } else if (token.type == Token::DIV) {
      Eat(Token::DIV);
      std::cout << result << "/=" << current_token_ << "\n";
      result /= Factor();
    }
  }
  return result;
}

void aequatio::lexer::Parser::Error() { throw "Invalid Syntax"; }

void aequatio::lexer::Parser::Eat(Token::Type type) {
  std::cout << current_token_.type << "==" << type << "\n";
  if (current_token_.type == type) {
    current_token_ = lexer_.GetNextToken();
  } else {
    Error();
  }
}

aequatio::lexer::Token aequatio::lexer::Parser::Factor() {
  Token token = current_token_;
  Eat(Token::DOUBLE);
  return token;
}
