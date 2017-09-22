#include "lexer/token.hpp"

#include <iostream>
#include <string>

aequatio::lexer::Token::Token() : type(NONE) {}
aequatio::lexer::Token::Token(Type type_) : type(type_) {}
aequatio::lexer::Token::Token(bool b, Type type_) : type(type_), bool_(b) {}
aequatio::lexer::Token::Token(int i, Type type_) : type(type_), int_(i) {}
aequatio::lexer::Token::Token(double d, Type type_) : type(type_), double_(d) {}
aequatio::lexer::Token::Token(char c, Type type_) : type(type_), char_(c) {}

aequatio::lexer::Token::Token(const Token& copy) : type(copy.type) {
  switch (copy.type) {
    case BOOL:
      bool_ = copy.bool_;
      break;
    case INTEGER:
      int_ = copy.int_;
      break;
    case DOUBLE:
      double_ = copy.double_;
      break;
    case CHAR:
      char_ = copy.char_;
      break;
    default:
      char_ = copy.char_;
      break;
  }
}

bool aequatio::lexer::Token::IsNumeric() const {
  if (type == INTEGER || type == DOUBLE) {
    return true;
  }
  return false;
}

bool aequatio::lexer::Token::IsValid() const {
  if (type == NONE) {
    return false;
  } else {
    return true;
  }
}

bool aequatio::lexer::Token::Bool() const { return bool_; }

int aequatio::lexer::Token::Int() const { return int_; }

double aequatio::lexer::Token::Double() const { return double_; }

char aequatio::lexer::Token::Char() const { return char_; }

void aequatio::lexer::Token::operator=(bool b) {
  type = BOOL;
  bool_ = b;
}
void aequatio::lexer::Token::operator=(int i) {
  type = INTEGER;
  int_ = i;
}
void aequatio::lexer::Token::operator=(double d) {
  type = DOUBLE;
  double_ = d;
}
void aequatio::lexer::Token::operator=(char c) {
  type = CHAR;
  char_ = c;
}

aequatio::lexer::Token& aequatio::lexer::Token::operator+=(const Token& rhs) {
  *this = *this + rhs;
  return *this;
}

aequatio::lexer::Token& aequatio::lexer::Token::operator-=(const Token& rhs) {
  *this = *this - rhs;
  return *this;
}

aequatio::lexer::Token& aequatio::lexer::Token::operator*=(const Token& rhs) {
  *this = *this * rhs;
  return *this;
}

aequatio::lexer::Token& aequatio::lexer::Token::operator/=(const Token& rhs) {
  *this = *this / rhs;
  return *this;
}

aequatio::lexer::Token::operator bool() const { return bool_; }
aequatio::lexer::Token::operator int() const { return int_; }
aequatio::lexer::Token::operator double() const { return double_; }
aequatio::lexer::Token::operator char() const { return char_; }

aequatio::lexer::Token aequatio::lexer::operator+(const Token& lhs,
                                                  const Token& rhs) {
  if ((lhs.type != rhs.type) &&
      (lhs.IsNumeric() == false || rhs.IsNumeric() == false)) {
    return Token();
  }
  if (lhs.type == Token::INTEGER && rhs.type == Token::DOUBLE) {
    return Token(lhs.int_ + rhs.double_);
  } else if (lhs.type == Token::DOUBLE && rhs.type == Token::INTEGER) {
    return Token(lhs.double_ + rhs.int_);
  }
  switch (lhs.type) {
    case Token::BOOL:
      return Token(lhs.bool_ + rhs.bool_);
    case Token::INTEGER:
      return Token(lhs.int_ + rhs.int_);
    case Token::DOUBLE:
      return Token(lhs.double_ + rhs.double_);
    case Token::CHAR:
      return Token(lhs.char_ + rhs.char_);
    default:
      break;
  }
  return Token();
}

aequatio::lexer::Token aequatio::lexer::operator-(const Token& lhs,
                                                  const Token& rhs) {
  Token token;
  if (lhs.type != rhs.type) {
    return token;
  }
  switch (lhs.type) {
    case Token::BOOL:
      token = (lhs.bool_ - rhs.bool_);
      break;
    case Token::INTEGER:
      token = (lhs.int_ - rhs.int_);
      break;
    case Token::DOUBLE:
      token = (lhs.double_ - rhs.double_);
      break;
    case Token::CHAR:
      token = (lhs.char_ - rhs.char_);
      break;
  }
  return token;
}

aequatio::lexer::Token aequatio::lexer::operator*(const Token& lhs,
                                                  const Token& rhs) {
  Token token;
  if (lhs.type != rhs.type) {
    return token;
  }
  switch (lhs.type) {
    case Token::BOOL:
      token = (lhs.bool_ * rhs.bool_);
      break;
    case Token::INTEGER:
      token = (lhs.int_ * rhs.int_);
      break;
    case Token::DOUBLE:
      token = (lhs.double_ * rhs.double_);
      break;
    case Token::CHAR:
      token = (lhs.char_ * rhs.char_);
      break;
  }
  return token;
}

aequatio::lexer::Token aequatio::lexer::operator/(const Token& lhs,
                                                  const Token& rhs) {
  Token token;
  if (lhs.type != rhs.type) {
    return token;
  }
  switch (lhs.type) {
    case Token::BOOL:
      token = (lhs.bool_ / rhs.bool_);
      break;
    case Token::INTEGER:
      token = (lhs.int_ / rhs.int_);
      break;
    case Token::DOUBLE:
      token = (lhs.double_ / rhs.double_);
      break;
    case Token::CHAR:
      token = (lhs.char_ / rhs.char_);
      break;
  }
  return token;
}

bool aequatio::lexer::operator==(const Token& lhs, const Token& rhs) {
  if (lhs.type != rhs.type) {
    return false;
  }
  switch (lhs.type) {
    case Token::BOOL:
      return lhs.bool_ == rhs.bool_;
    case Token::INTEGER:
      return lhs.int_ == rhs.int_;
    case Token::DOUBLE:
      return lhs.double_ == rhs.double_;
    case Token::CHAR:
      return lhs.char_ == rhs.char_;
    default:
      return lhs.type == rhs.type;
  }
}

bool aequatio::lexer::operator!=(const Token& lhs, const Token& rhs) {
  return !(lhs == rhs);
}

bool aequatio::lexer::operator>(const Token& lhs, const Token& rhs) {
  if (lhs.type != rhs.type) {
    return false;
  }
  switch (lhs.type) {
    case Token::BOOL:
      return lhs.bool_ > rhs.bool_;
    case Token::INTEGER:
      return lhs.int_ > rhs.int_;
    case Token::DOUBLE:
      return lhs.double_ > rhs.double_;
    case Token::CHAR:
      return lhs.char_ > rhs.char_;
    default:
      return false;
  }
}

bool aequatio::lexer::operator<(const Token& lhs, const Token& rhs) {
  return !((lhs > rhs) || lhs == rhs);
}

bool aequatio::lexer::operator>=(const Token& lhs, const Token& rhs) {
  return ((lhs > rhs) || lhs == rhs);
}

bool aequatio::lexer::operator<=(const Token& lhs, const Token& rhs) {
  return !(lhs > rhs);
}

bool aequatio::lexer::operator&&(const Token& lhs, const Token& rhs) {
  if (lhs.type != rhs.type) {
    return false;
  }
  switch (lhs.type) {
    case Token::BOOL:
      return lhs.bool_ && rhs.bool_;
    default:
      return lhs == rhs;
  }
}

bool aequatio::lexer::operator||(const Token& lhs, const Token& rhs) {
  bool ret = false;
  if (lhs.type == Token::BOOL && lhs.bool_ == true) {
    ret = true;
  } else if (rhs.type == Token::BOOL && rhs.bool_ == true) {
    ret == true;
  }
  return ret;
}

bool aequatio::lexer::operator!(const Token& t) {
  if (t.type == Token::BOOL) {
    return !(t.bool_);
  } else {
    return true;
  }
}

std::ostream& aequatio::lexer::operator<<(std::ostream& out, const Token& t) {
  switch (t.type) {
    case Token::BOOL:
      out << t.bool_;
      break;
    case Token::INTEGER:
      out << t.int_;
      break;
    case Token::DOUBLE:
      out << t.double_;
      break;
    case Token::CHAR:
      out << t.char_;
      break;
    default:
      out << "(null)";
  }
  return out;
}

std::istream& aequatio::lexer::operator>>(std::istream& in, Token& t) {
  std::string str;
  int len;
  in >> str;
  len = str.size();
  if (len == 0) {
    return in;
  }
  bool has_dot = false, integer = true;
  for (int i = 0; i < len; i++) {
    if ((str[i] > 57 || str[i] < 48) && str[i] != 46) {
      integer = false;
    } else if (str[i] == 46 && integer == true) {
      if (has_dot == true) {
        integer = false;
      } else {
        has_dot = true;
      }
    }
  }
  if (integer == false) {
    if (str == "true" || str == "True" || str == "TRUE") {
      t = true;
    } else if (str == "false" || str == "False" || str == "FALSE") {
      t = false;
    } else {
      t = str[0];
    }
  } else if (integer == true) {
    if (has_dot == true) {
      t = stod(str);
    } else {
      t = stoi(str);
    }
  }
  return in;
}
