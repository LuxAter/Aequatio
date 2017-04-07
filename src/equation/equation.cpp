#include <math.h>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "equation.hpp"
#include "term.hpp"

aequatio::Equation::Equation() {
  str_infix = "";
  str_rpn = "";
}

aequatio::Equation::Equation(std::string str) {
  str_infix = str;
  str_rpn = "";
}

aequatio::Equation::~Equation() {
  str_infix = "";
  str_rpn = "";
}

std::string aequatio::Equation::String(int format) {
  if (format == E_INFIX) {
    return (str_infix);
  } else if (format == E_RPN) {
    return (str_rpn);
  }
  return (std::string());
}

void aequatio::Equation::Parse(int format) {
  if (format == SHUNTING_YARD) {
    LoadTerms();
    ShuntingYard();
  }
}

void aequatio::Equation::LoadTerms() {
  terms_infix.clear();
  std::string sub_string = "";
  for (int i = 0; i < str_infix.size(); i++) {
    if (str_infix[i] == ' ') {
      terms_infix.push_back(Term(sub_string));
      sub_string = "";
    } else {
      sub_string += str_infix[i];
    }
  }
  terms_infix.push_back(Term(sub_string));
  str_infix = "";
  for (int i = 0; i < terms_infix.size(); i++) {
    str_infix += terms_infix[i].str + " ";
  }
  if (str_infix.size() > 0) {
    str_infix.pop_back();
  }
}

void aequatio::Equation::ShuntingYard() {
  terms_rpn.clear();
  std::stack<Term> operators;
  for (int i = 0; i < terms_infix.size(); i++) {
    if (terms_infix[i].type == T_VALUE || terms_infix[i].type == T_VAR) {
      // Term is a value or variable
      // Add directly out the output queue
      terms_rpn.push_back(terms_infix[i]);
    } else if (terms_infix[i].type == T_PAREN) {
      // Term is a Paren
      if (terms_infix[i].str == "(") {
        operators.push(terms_infix[i]);
      } else if (terms_infix[i].str == ")") {
        while (operators.empty() == false && operators.top().str != "(") {
          terms_rpn.push_back(operators.top());
          operators.pop();
        }
        if (operators.empty() == false && operators.top().str == "(") {
          operators.pop();
        }
      }
    } else if (terms_infix[i].type == T_OP) {
      while (operators.empty() == false &&
             operators.top().prec >= terms_infix[i].prec &&
             operators.top().str != terms_infix[i].str) {
        terms_rpn.push_back(operators.top());
        operators.pop();
      }
      operators.push(terms_infix[i]);
    }
  }
  while (operators.empty() == false) {
    terms_rpn.push_back(operators.top());
    operators.pop();
  }
  str_rpn = "";
  for (int i = 0; i < terms_rpn.size(); i++) {
    str_rpn += terms_rpn[i].str + " ";
  }
  if (str_rpn.size() > 0) {
    str_rpn.pop_back();
  }
}
