#ifndef AEQUATIO_LEXER_TOKEN_HPP
#define AEQUATIO_LEXER_TOKEN_HPP

#include <iostream>
#include <variant>

namespace aequatio::lexer {
  class Token {
   public:
    enum Type { NONE, END_OF_FILE, BOOL, INTEGER, DOUBLE, CHAR, MUL, DIV };

    Token();
    Token(Type type_);
    Token(bool b, Type type_ = BOOL);
    Token(int i, Type type_ = INTEGER);
    Token(double d, Type type_ = DOUBLE);
    Token(char c, Type type_ = CHAR);
    Token(const Token& copy);

    bool IsNumeric() const;
    bool IsValid() const;

    bool Bool() const;
    int Int() const;
    double Double() const;
    char Char() const;

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
}  // namespace aequatio::lexer

#endif /* ifndef AEQUATIO_LEXER_TOKEN_HPP */
