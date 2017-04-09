#ifndef AEQUATIO_NUMBER_HPP
#define AEQUATIO_NUMBER_HPP
#include <string>
#include "../../symbol.hpp"
namespace aequatio {
  class Number : public Symbol {
   public:
    Number();
    Number(double in_val);
    ~Number();
    int Type();
    std::string String();
    void Sum(Symbol* a, Symbol* b);
    double val;

   private:
  };
}
#endif
