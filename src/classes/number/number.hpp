#ifndef AEQUATIO_NUMBER_HPP
#define AEQUATIO_NUMBER_HPP
#include <string>
#include "../base.hpp"
namespace aequatio {
  class Number : public Base {
   public:
    Number();
    Number(double in_val);
    ~Number();
    int Type();
    std::string String();
    double val;

   private:
  };
  Number operator+(const Number& a, const Number& b);
  Number operator-(const Number& a, const Number& b);
  Number operator*(const Number& a, const Number& b);
  Number operator/(const Number& a, const Number& b);
  bool operator==(const Number& a, const Number& b);
}
#endif
