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

   private:
    std::string eq_string, rpn_string;
  };
}
#endif
