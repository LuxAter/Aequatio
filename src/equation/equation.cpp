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
}

aequatio::Equation::~Equation() {
  eq_string = "";
  rpn_string = "";
}
