#ifndef AEQUATIO_OBJECT_COMPLEX_COMPLEX_OP_HPP
#define AEQUATIO_OBJECT_COMPLEX_COMPLEX_OP_HPP
#include "complex.hpp"
namespace aequatio{
  Complex operator+(const Complex& a, const Complex& b);
  Complex operator-(const Complex& a, const Complex& b);
  Complex operator*(const Complex& a, const Complex& b);
  Complex operator/(const Complex& a, const Complex& b); 
};
#endif
