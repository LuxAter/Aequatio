#ifndef AEQUATIO_EQUAITON_HPP
#define AEQUATIO_EQUAITON_HPP
#include <string>
#include <vector>
#include "term.hpp"
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

   private:
    void LoadTerms();
    void ShuntingYard();
    std::vector<Term> terms_infix, terms_rpn;
    std::string str_infix, str_rpn;
  };
}
#endif
