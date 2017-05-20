#include <sstream>
#include "../types.hpp"
#include "complex.hpp"

aequatio::Complex::Complex(){
  real = double();
  imag = double();
}

aequatio::Complex::Complex(const Complex& copy){
  real = copy.real;
  imag = copy.imag;
}

aequatio::Complex::Complex(double in_real, double in_imag){
  real = in_real;
  imag = in_imag;
}

aequatio::Complex::~Complex(){
  real = double();
  imag = double();
}

int aequatio::Complex::Type(){
  return(AEQ_OBJ_COMPLEX);
}

std::string aequatio::Complex::String(){
  std::stringstream stream;
  std::string out, temp;
  stream << real;
  stream >> temp;
  out = temp + "+";
  stream << imag;
  stream >> temp;
  out += temp + "i";
  return(out);
}
