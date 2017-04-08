#ifndef AEQUATIO_NUMBER_HPP
#define AEQUATIO_NUMBER_HPP
#include "../../symbol.hpp"
namespace aequatio {
  class Number : public Symbol {
   public:
    Number();
    Number(double in_val);
    ~Number();
    int Type();
    double inline operator()() { return (val); }
    double val;

   private:
  };
}
#endif
