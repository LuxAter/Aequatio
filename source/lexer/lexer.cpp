#include "lexer/lexer.hpp"

#include <string>

#include "lexer/token.hpp"

aequatio::lexer::Lexer::Lexer() {}

aequatio::lexer::Lexer::Lexer(std::string text) : text_(text), index_(0) {
  if (text_.size() > 0) {
    current_char_ = text_[index_];
  } else {
    current_char_ = char(0);
  }
}

aequatio::lexer::Lexer::Lexer(const Lexer& copy)
    : text_(copy.text_),
      current_char_(copy.current_char_),
      index_(copy.index_) {}

void aequatio::lexer::Lexer::Error() { throw "Invalid Character"; }

void aequatio::lexer::Lexer::Advance() {
  index_++;
  if (index_ >= text_.size()) {
    current_char_ = char(0);
  } else {
    current_char_ = text_[index_];
  }
}

void aequatio::lexer::Lexer::SkipWhitespace() {
  while (current_char_ == ' ') {
    Advance();
  }
}

aequatio::lexer::Token aequatio::lexer::Lexer::Integer() {
  Token result(0);
  while (current_char_ >= 48 && current_char_ <= 57) {
    result *= 10;
    result += int(current_char_) - 48;
    Advance();
  }
  return result;
}

aequatio::lexer::Token aequatio::lexer::Lexer::GetNextToken() {
  while (current_char_ != char(0)) {
    if (current_char_ == ' ') {
      SkipWhitespace();
    } else if (current_char_ >= 48 && current_char_ <= 57) {
      return Integer();
    } else if (current_char_ == '*') {
      Advance();
      return Token(current_char_, Token::MUL);
    } else if (current_char_ == '/') {
      Advance();
      return Token(current_char_, Token::DIV);
    } else {
      Error();
    }
  }
  return Token(char(0), Token::END_OF_FILE);
}