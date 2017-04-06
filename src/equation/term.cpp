#include <iostream>
#include <string>
#include "term.hpp"

aequatio::Term::Term() {
  term_type = TERM_NULL;
  term_string = std::string();
  term_value = double();
  term_weight = 0;
  n_operator_arg = 0;
}

aequatio::Term::Term(std::string str) {
  bool numbers = true, capital = false, found = false;
  n_operator_arg = 0;
  int deci = 0;
  term_string = str;
  if (str.size() == 1) {
    if (str == "(") {
      term_type = TERM_GROUPING;
      term_weight = 1;
      found = true;
    } else if (str == ")") {
      term_type = TERM_GROUPING;
      term_weight = 1;
      found = true;
    } else if (str == "*") {
      term_type = TERM_OPERATOR;
      term_weight = 3;
      n_operator_arg = 2;
      found = true;
    } else if (str == "/") {
      term_type = TERM_OPERATOR;
      term_weight = 3;
      n_operator_arg = 2;
      found = true;
    } else if (str == "+") {
      term_type = TERM_OPERATOR;
      term_weight = 2;
      n_operator_arg = 2;
      found = true;
    } else if (str == "-") {
      term_type = TERM_OPERATOR;
      term_weight = 2;
      n_operator_arg = 2;
      found = true;
    } else if (str == "^") {
      term_type = TERM_OPERATOR;
      term_weight = 4;
      n_operator_arg = 2;
      found = true;
    }
  }
  for (int i = 0; i < str.size() && found == false; i++) {
    if (i == 0 && int(str[i]) >= 65 && int(str[i]) <= 90) {
      capital = true;
    }
    if ((int(str[i]) > 57 || int(str[i]) < 48) && int(str[i]) != 46) {
      numbers = false;
    }
    if (int(str[i]) == 46) {
      deci++;
    }
  }
  if (found == false) {
    if (numbers == true && deci <= 1) {
      term_type = TERM_VALUE;
      term_value = stod(str);
      term_weight = 0;
    } else if (capital == true) {
      term_type = TERM_FUNCTION;
      n_operator_arg = 1;
      term_weight = 6;
    } else {
      term_type = TERM_VARIABLE;
      term_weight = 0;
    }
  }
}

aequatio::Term::~Term() {
  term_type = int();
  term_string = std::string();
  term_value = double();
}
