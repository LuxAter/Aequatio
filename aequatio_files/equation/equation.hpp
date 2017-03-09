#ifndef AEQUATIO_EQUATION_EQUATION_HPP
#define AEQUATIO_EQUATION_EQUATION_HPP
#include "../functions/triple.hpp"
#include <string>
#include <tuple>
#include <vector>
namespace aequatio {
enum TermType {
  NO_TYPE = 0,
  FUNCTION = 1,
  VARIABLE = 2,
  VALUE = 3,
  OPERATION = 4,
  OPEN1 = 5,
  OPEN2 = 6,
  OPEN3 = 7,
  CLOSE1 = 8,
  CLOSE2 = 9,
  CLOSE3 = 10
};
enum StringMode { STR_DEFAULT = 0, STR_TYPE = 1, STR_VALUE = 2 };
class Equation {
public:
  Equation();
  Equation(std::string equation);
  ~Equation();
  std::string EquationString(int string_mode = 0);
  double operator()(std::string name, double val);
  void SetEquation(std::string equation);
  bool ValueString(std::string str);
  // double operator()(std::vector<double> vars);

private:
  void ParseEquation();
  void DivideString();
  int IsOperator(std::string str);
  int IsParen(std::string str);
  int FindVar(std::string name);
  int FindConst(double val);
  std::string equation_string;
  std::vector<std::string> term_strings;
  std::vector<triple<int, int, double>> terms;
  std::vector<std::pair<std::string, double>> variables;
  std::vector<std::pair<std::string, double>> constants;
};
}
#endif
