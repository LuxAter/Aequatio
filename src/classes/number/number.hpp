#ifndef AEQUATIO_NUMBER_HPP
#define AEQUATIO_NUMBER_HPP
#include "../../symbol.hpp"
#include <string>
namespace aequatio {
  class Number : public Symbol {
   public:
    Number();
    Number(double in_val);
    ~Number();
    int Type();
    std::string String();
    double val;

   private:
  };
}
#endif
