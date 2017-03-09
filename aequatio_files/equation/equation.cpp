#include "../aequatio.hpp"
#include "../functions/triple.hpp"
#include "equation.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

aequatio::Equation::Equation() {}

aequatio::Equation::Equation(std::string equation) {
  equation_string = equation;
  ParseEquation();
}

aequatio::Equation::~Equation() {
  term_strings.clear();
  terms.clear();
  variables.clear();
  constants.clear();
}

std::string aequatio::Equation::EquationString(int string_mode) {
  if (string_mode == STR_DEFAULT) {
    return (equation_string);
  } else if (string_mode == STR_TYPE) {
    std::string type_string = "";
    for (int i = 0; i < terms.size(); i++) {
      if (terms[i].first == FUNCTION) {
        type_string += "FUNCTION ";
      } else if (terms[i].first == VARIABLE) {
        type_string += "VARIABLE ";
      } else if (terms[i].first == VALUE) {
        type_string += "VALUE ";
      } else if (terms[i].first == OPERATION) {
        type_string += "OPERATION ";
      } else if (terms[i].first == OPEN1) {
        type_string += "( ";
      } else if (terms[i].first == OPEN2) {
        type_string += "[ ";
      } else if (terms[i].first == OPEN3) {
        type_string += "{ ";
      } else if (terms[i].first == CLOSE1) {
        type_string += ") ";
      } else if (terms[i].first == CLOSE2) {
        type_string += "] ";
      } else if (terms[i].first == CLOSE3) {
        type_string += "} ";
      } else if (terms[i].first == NO_TYPE) {
        type_string += "ERR";
      }
    }
    return (type_string);
  }
  return ("");
}

double aequatio::Equation::operator()(std::string name, double val) {
  for (int i = 0; i < variables.size(); i++) {
    if (name == variables[i].first) {
      variables[i].second = val;
    }
  }
  std::vector<triple<int, int, double>> solve_terms = terms;
  for (int i = 0; i < solve_terms.size(); i++) {
    if (solve_terms[i].first == VARIABLE) {
      solve_terms[i].third = variables[solve_terms[i].second].second;
      solve_terms[i].first = VALUE;
    } else if (solve_terms[i].first == VALUE) {
      solve_terms[i].third = constants[solve_terms[i].second].second;
    }
  }
  while (solve_terms.size() > 2) {
    for (int j = 4; j >= 0; j--) {
      for (int i = 0; i < solve_terms.size(); i++) {
        if (i != 0 && solve_terms[i].first == OPERATION &&
            solve_terms[i].second == j) {
          if (solve_terms[i].second == 1) {
            solve_terms[i - 1].third += solve_terms[i + 1].third;
          } else if (solve_terms[i].second == 2) {
            solve_terms[i - 1].third -= solve_terms[i + 1].third;
          } else if (solve_terms[i].second == 3) {
            solve_terms[i - 1].third /= solve_terms[i + 1].third;
          } else if (solve_terms[i].second == 4) {
            solve_terms[i - 1].third *= solve_terms[i + 1].third;
          }
          solve_terms.erase(solve_terms.begin() + i,
                            solve_terms.begin() + i + 1);
          // std::cout << solve_terms[i - 1].third << "->";
        }
      }
    }
  }
  // return (0);
  return (solve_terms[0].third);
}

void aequatio::Equation::SetEquation(std::string equation) {
  term_strings.clear();
  terms.clear();
  variables.clear();
  constants.clear();
  equation_string = equation;
  ParseEquation();
}

// double aequatio::Equation::operator()(std::vector<double> vars) {
//   double result = 0;
//   return (result);
// }

void aequatio::Equation::ParseEquation() {
  DivideString();
  for (int i = 0; i < term_strings.size(); i++) {
    triple<int, int, double> term(0, 0, 0.0);
    int function_index = FindFunction(term_strings[i]);
    int operation_index = IsOperator(term_strings[i]);
    int paren_index = IsParen(term_strings[i]);
    if (function_index != -1) {
      term.first = FUNCTION;
      term.second = function_index;
    } else if (operation_index != 0) {
      term.first = OPERATION;
      term.second = operation_index;
    } else if (paren_index != 0) {
      term.first = paren_index;
    } else if (ValueString(term_strings[i])) {
      term.first = VALUE;
      int val_index = FindConst(stod(term_strings[i]));
      if (val_index != -1) {
        term.second = val_index;
      } else if (val_index == -1) {
        std::pair<std::string, double> new_const(term_strings[i],
                                                 stod(term_strings[i]));
        constants.push_back(new_const);
        term.second = constants.size() - 1;
      }
    } else {
      term.first = VARIABLE;
      int var_index = FindVar(term_strings[i]);
      if (var_index != -1) {
        term.second = var_index;
      } else if (var_index == -1) {
        std::pair<std::string, double> new_var(term_strings[i], 0.0f);
        variables.push_back(new_var);
        term.second = variables.size() - 1;
      }
    }
    terms.push_back(term);
  }
}

void aequatio::Equation::DivideString() {
  std::string term_str = "";
  for (int i = 0; i < equation_string.size(); i++) {
    if (equation_string[i] == ' ') {
      term_strings.push_back(term_str);
      term_str = "";
    } else {
      term_str += equation_string[i];
    }
  }
  term_strings.push_back(term_str);
}

bool aequatio::Equation::ValueString(std::string str) {
  for (int i = 0; i < str.size(); i++) {
    if (int(str[i]) != 46 && (int(str[i]) > 57 || int(str[i]) < 48)) {
      return (false);
    }
  }
  return (true);
}

int aequatio::Equation::IsOperator(std::string str) {
  if (str == "+") {
    return (1);
  } else if (str == "-") {
    return (2);
  } else if (str == "/") {
    return (3);
  } else if (str == "*") {
    return (4);
  }
  return (0);
  // return (str == "+" || str == "=" || str == "-" || str == "/" || str == ">"
  // ||
  //         str == "<" || str == "!" || str == "%" || str == "^" || str ==
  //         "*");
}

int aequatio::Equation::IsParen(std::string str) {
  if (str == "(") {
    return (OPEN1);
  } else if (str == "[") {
    return (OPEN2);
  } else if (str == "{") {
    return (OPEN3);
  } else if (str == ")") {
    return (CLOSE1);
  } else if (str == "]") {
    return (CLOSE2);
  } else if (str == "}") {
    return (CLOSE3);
  }
  return (0);
}

int aequatio::Equation::FindVar(std::string name) {
  for (int i = 0; i < variables.size(); i++) {
    if (name == std::get<0>(variables[i])) {
      return (i);
    }
  }
  return (-1);
}

int aequatio::Equation::FindConst(double val) {
  for (int i = 0; i < constants.size(); i++) {
    if (val == constants[i].second) {
      return (i);
    }
  }
  return (-1);
}
