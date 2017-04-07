#include <iostream>
#include <string>
#include "function.hpp"
#include "term.hpp"

aequatio::Term::Term() {
  str = std::string();
  alt_str = std::string();
  type = T_NONE;
  assoc = A_NONE;
  prec = -1;
  value = double();
}

aequatio::Term::Term(std::string term_str) {
  str = term_str;
  alt_str = std::string();
  type = T_NONE;
  assoc = A_NONE;
  prec = -1;
  value = double();
  LoadType();
}

aequatio::Term::~Term() {
  type = int();
  assoc = int();
  prec = int();
  value = double();
  str = std::string();
}

int aequatio::Term::LoadType() {
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
    value = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' || endptr == str.c_str()) {
      value = double();
      type = T_VAR;
    } else {
      type = T_VALUE;
    }
  }
  return (0);
}
