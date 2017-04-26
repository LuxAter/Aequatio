#include <math.h>
#include <pessum.h>
#include <limits>
#include <sstream>
#include <string>
#include "../types.hpp"
#include "number.hpp"

aequatio::Number::Number() {}

aequatio::Number::Number(double in_val) { val = in_val; }

aequatio::Number::~Number() {}

int aequatio::Number::Type() { return (SY_NUMBER); }

std::string aequatio::Number::String() {
  std::stringstream ss;
  std::string out;
  ss << val;
  ss >> out;
  return (out);
}

aequatio::Number aequatio::operator+(const Number& a, const Number& b) {
  return (Number(a.val + b.val));
}

aequatio::Number aequatio::operator-(const Number& a, const Number& b) {
  return (Number(a.val - b.val));
}

aequatio::Number aequatio::operator*(const Number& a, const Number& b) {
  return (Number(a.val * b.val));
}

aequatio::Number aequatio::operator/(const Number& a, const Number& b) {
  if (fabs(b.val) <= std::numeric_limits<double>::min()) {
    pessum::Log(pessum::WARNING, "Dividing by %f", "number/number/operator/",
                b.val);
  }
  return (Number(a.val / b.val));
}

bool aequatio::operator==(const Number& a, const Number& b) {
  return (a.val == b.val);
}

bool aequatio::operator<(const Number& a, const Number& b){
  return(a.val < b.val);
}

bool aequatio::operator!=(const Number& a, const Number& b){
  return(!(a.val == b.val));
}

bool aequatio::operator>(const Number& a, const Number& b){
  return(b.val > a.val);
}

bool aequatio::operator<=(const Number& a, const Number& b){
  return(!(b.val < a.val));
}

bool aequatio::operator>=(const Number& a, const Number& b){
  return(!(a.val < b.val));
}
