#ifndef AEQUATIO_OBJECT_NUMBER_NUMBER_OP_HPP
#define AEQUATIO_OBJECT_NUMBER_NUMBER_OP_HPP
#include "number.hpp"
namespace aequatio{
  Number operator+(const Number& a, const Number& b);
  Number operator-(const Number& a, const Number& b);
  Number operator*(const Number& a, const Number& b);
  Number operator/(const Number& a, const Number& b);
}
#endif
