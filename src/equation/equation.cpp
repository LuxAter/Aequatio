#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include "equation.hpp"
#include "term.hpp"

aequatio::Equation::Equation() {
  eq_string = "";
  rpn_string = "";
}

aequatio::Equation::Equation(std::string str) {
  eq_string = str;
  rpn_string = "";
  ParseEquationString();
}

aequatio::Equation::~Equation() {
  eq_string = "";
  rpn_string = "";
}

double aequatio::Equation::operator()() {
  std::stack<Term> operands;
  for (int i = 0; i < rpn_terms.size(); i++) {
    if (rpn_terms[i].term_type == TERM_VALUE) {
      operands.push(rpn_terms[i]);
    } else if (rpn_terms[i].term_type == TERM_OPERATOR) {
      Term term = operands.top();
      operands.pop();
      if (rpn_terms[i].term_string == "+") {
        operands.top().term_value = operands.top().term_value + term.term_value;
      } else if (rpn_terms[i].term_string == "-") {
        operands.top().term_value = operands.top().term_value - term.term_value;
      } else if (rpn_terms[i].term_string == "*") {
        operands.top().term_value = operands.top().term_value * term.term_value;
      } else if (rpn_terms[i].term_string == "/") {
        operands.top().term_value = operands.top().term_value / term.term_value;
      } else if (rpn_terms[i].term_string == "^") {
        operands.top().term_value =
            pow(operands.top().term_value, term.term_value);
      }
    }
  }
  return (operands.top().term_value);
}

std::string aequatio::Equation::String() {
  eq_string = "";
  for (int i = 0; i < eq_terms.size(); i++) {
    eq_string += eq_terms[i].term_string;
  }
  return (eq_string);
}

std::string aequatio::Equation::RpnString() {
  rpn_string = "";
  for (int i = 0; i < rpn_terms.size(); i++) {
    rpn_string += rpn_terms[i].term_string;
  }
  return (rpn_string);
}

void aequatio::Equation::ParseEquationTerms() {
  std::string sub_string = std::string();
  for (int i = 0; i < eq_string.size(); i++) {
    if (eq_string[i] == ' ') {
      eq_terms.push_back(Term(sub_string));
      sub_string = std::string();
    } else {
      sub_string += eq_string[i];
    }
  }
  eq_terms.push_back(Term(sub_string));
}
void aequatio::Equation::ParseEquationString() {
  ParseEquationTerms();
  std::stack<Term> operator_stack;
  for (int i = 0; i < eq_terms.size(); i++) {
    if (eq_terms[i].term_type == TERM_OPERATOR ||
        eq_terms[i].term_type == TERM_FUNCTION) {
      while (operator_stack.empty() == false &&
             operator_stack.top().term_weight >= eq_terms[i].term_weight) {
        rpn_terms.push_back(operator_stack.top());
        operator_stack.pop();
      }
      operator_stack.push(eq_terms[i]);
    } else if (eq_terms[i].term_type == TERM_GROUPING) {
      if (eq_terms[i].term_string == "(") {
        operator_stack.push(eq_terms[i]);
      } else if (eq_terms[i].term_string == ")") {
        while (operator_stack.empty() == false &&
               operator_stack.top().term_string != "(") {
          rpn_terms.push_back(operator_stack.top());
          operator_stack.pop();
        }
      }
    } else if (eq_terms[i].term_type == TERM_VALUE ||
               eq_terms[i].term_type == TERM_VARIABLE) {
      rpn_terms.push_back(eq_terms[i]);
    }
  }
  while (operator_stack.empty() == false) {
    if (operator_stack.top().term_type != TERM_GROUPING) {
      rpn_terms.push_back(operator_stack.top());
    }
    operator_stack.pop();
  }
}
