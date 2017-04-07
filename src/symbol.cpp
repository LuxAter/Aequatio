#include <math.h>
#include <iostream>
#include <string>
#include "symbol.hpp"

aequatio::Symbol::Symbol() {
  str = std::string();
  alt_str = std::string();
  type = T_NONE;
  assoc = A_NONE;
  prec = -1;
  val_double = double();
}

aequatio::Symbol::Symbol(std::string term_str) {
  str = term_str;
  alt_str = std::string();
  type = T_NONE;
  assoc = A_NONE;
  prec = -1;
  val_double = double();
  LoadType();
}

aequatio::Symbol::Symbol(double val) {
  str = std::string();
  alt_str = std::string();
  type = T_VALUE;
  assoc = A_NONE;
  prec = -1;
  val_type = V_NUM;
  val_double = val;
}

aequatio::Symbol::Symbol(int val) {
  str = std::string();
  alt_str = std::string();
  type = T_VALUE;
  assoc = A_NONE;
  prec = -1;
  val_type = V_NUM;
  val_double = val;
}

aequatio::Symbol::~Symbol() {
  type = int();
  assoc = int();
  prec = int();
  val_double = double();
  str = std::string();
}

int aequatio::Symbol::LoadType() {
  if (str == "(") {
    prec = 0;
    type = T_PAREN;
    assoc = A_NONE;
    return (1);
  } else if (str == ")") {
    prec = 0;
    type = T_PAREN;
    assoc = A_NONE;
    return (1);
  } else if (str == "^") {
    prec = 4;
    type = T_OP;
    assoc = A_RIGHT;
    return (1);
  } else if (str == "*") {
    prec = 3;
    type = T_OP;
    assoc = A_LEFT;
    return (1);
  } else if (str == "/") {
    prec = 3;
    type = T_OP;
    assoc = A_LEFT;
    return (1);
  } else if (str == "+") {
    prec = 2;
    type = T_OP;
    assoc = A_LEFT;
    return (1);
  } else if (str == "-") {
    prec = 2;
    type = T_OP;
    assoc = A_LEFT;
    return (1);
  } else if (str.size() >= 1 && str[0] >= 'A' && str[0] <= 'Z') {
    prec = 5;
    type = T_FUNC;
    assoc = A_LEFT;
  } else {
    prec = -1;
    assoc = A_NONE;
    char* endptr = 0;
    val_double = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' || endptr == str.c_str()) {
      type = T_VAR;
    } else {
      type = T_VALUE;
      val_type = V_NUM;
    }
  }
  return (0);
}

aequatio::Symbol aequatio::Pow(const Symbol& a, const Symbol& b) {
  Symbol new_term;
  new_term.type = T_VALUE;
  if (a.val_type == V_NUM && b.val_type == V_NUM) {
    new_term.val_type = V_NUM;
    new_term.val_double = pow(a.val_double, b.val_double);
  }
  return (new_term);
}

aequatio::Symbol aequatio::operator+(const Symbol& a, const Symbol& b) {
  Symbol new_term;
  new_term.type = T_VALUE;
  if (a.val_type == V_NUM && b.val_type == V_NUM) {
    new_term.val_type = V_NUM;
    new_term.val_double = a.val_double + b.val_double;
  }
  return (new_term);
}
aequatio::Symbol aequatio::operator-(const Symbol& a, const Symbol& b) {
  Symbol new_term;
  new_term.type = T_VALUE;
  if (a.val_type == V_NUM && b.val_type == V_NUM) {
    new_term.val_type = V_NUM;
    new_term.val_double = a.val_double - b.val_double;
  }
  return (new_term);
}
aequatio::Symbol aequatio::operator*(const Symbol& a, const Symbol& b) {
  Symbol new_term;
  new_term.type = T_VALUE;
  if (a.val_type == V_NUM && b.val_type == V_NUM) {
    new_term.val_type = V_NUM;
    new_term.val_double = a.val_double * b.val_double;
  }
  return (new_term);
}
aequatio::Symbol aequatio::operator/(const Symbol& a, const Symbol& b) {
  Symbol new_term;
  new_term.type = T_VALUE;
  if (a.val_type == V_NUM && b.val_type == V_NUM) {
    new_term.val_type = V_NUM;
    new_term.val_double = a.val_double / b.val_double;
  }
  return (new_term);
}
