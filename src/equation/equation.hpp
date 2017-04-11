#ifndef AEQUATIO_EQUAITON_HPP
#define AEQUATIO_EQUAITON_HPP
#include <map>
#include <string>
#include <vector>
#include "../classes/class_headers.hpp"
namespace aequatio {
  enum EQUATION_FORMAT { E_INFIX, E_RPN };
  enum PARSE_FORMAT { SHUNTING_YARD };
  class Equation {
   public:
    Equation();
    Equation(std::string str);
    ~Equation();
    std::string String(int format);
    void Parse(int format);
    void SetVariables(std::map<std::string, Symbol*> vars);
    Symbol operator()();

   private:
    void LoadSymbols();
    void ShuntingYard();
    void Solve();
    Symbol output;
    std::map<std::string, Symbol*> var_map;
    std::vector<Symbol *> terms_infix, terms_rpn;
    std::string str_infix, str_rpn;
  };
}
#endif
