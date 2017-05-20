#include "number_op.hpp"
#include "number.hpp"

aequatio::Number aequatio::operator+(const Number& a, const Number& b){
  return(Number(a.value + b.value));
}

aequatio::Number aequatio::operator-(const Number& a, const Number& b){
  return(Number(a.value - b.value));
}

aequatio::Number aequatio::operator*(const Number& a, const Number& b){
  return(Number(a.value * b.value));
}

aequatio::Number aequatio::operator/(const Number& a, const Number& b){
  return(Number(a.value / b.value));
}
