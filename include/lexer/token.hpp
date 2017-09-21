#ifndef AEQUATIO_LEXER_TOKEN_HPP
#define AEQUATIO_LEXER_TOKEN_HPP

#include <iostream>
#include <variant>

namespace aequatio::lexer {
  class Token {
   public:
    enum Type { NONE, BOOL, INTEGER, DOUBLE, CHAR, PLUS };

    Token();
    Token(bool b, Type type_ = BOOL);
    Token(int i, Type type_ = INTEGER);
    Token(double d, Type type_ = DOUBLE);
    Token(char c, Type type_ = CHAR);
    Token(const Token& token);

    bool IsNumeric() const;

    void operator=(bool b);
    void operator=(int i);
    void operator=(double d);
    void operator=(char c);

    Token& operator+=(const Token& rhs);
    Token& operator-=(const Token& rhs);
    Token& operator*=(const Token& rhs);
    Token& operator/=(const Token& rhs);

    operator bool() const;
    operator int() const;
    operator double() const;
    operator char() const;

    Type type;
    union {
      bool bool_;
      int int_;
      double double_;
      char char_;
    };
  };

  Token operator+(const Token& lhs, const Token& rhs);
  Token operator-(const Token& lhs, const Token& rhs);
  Token operator*(const Token& lhs, const Token& rhs);
  Token operator/(const Token& lhs, const Token& rhs);

  bool operator==(const Token& lhs, const Token& rhs);
  bool operator!=(const Token& lhs, const Token& rhs);
  bool operator>(const Token& lhs, const Token& rhs);
  bool operator<(const Token& lhs, const Token& rhs);
  bool operator>=(const Token& lhs, const Token& rhs);
  bool operator<=(const Token& lhs, const Token& rhs);

  bool operator&&(const Token& lhs, const Token& rhs);
  bool operator||(const Token& lhs, const Token& rhs);
  bool operator!(const Token& t);

  std::ostream& operator<<(std::ostream& out, const Token& t);
  std::istream& operator>>(std::istream& in, Token& t);
}  // namespace aequatio

#endif /* ifndef AEQUATIO_LEXER_TOKEN_HPP */
