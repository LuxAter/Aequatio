#ifndef AEQUATIO_EQUAITON_HPP
#define AEQUATIO_EQUAITON_HPP
#include <string>
#include <vector>
#include "term.hpp"
namespace aequatio {
  class Equation {
   public:
    Equation();
    Equation(std::string str);
    ~Equation();
    double operator()();
    std::string String();
    std::string RpnString();

   private:
    void ParseEquationTerms();
    void ParseEquationString();
    std::string eq_string, rpn_string;
    std::vector<Term> eq_terms, rpn_terms;
  };
}
#endif
