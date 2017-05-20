#include <sstream>
#include "../object.hpp"
#include "../types.hpp"
#include "number.hpp"

aequatio::Number::Number() { value = double(); }

aequatio::Number::Number(const Number& copy) { value = copy.value; }

aequatio::Number::Number(double in_value) { value = in_value; }

aequatio::Number::~Number() { value = double(); }

int aequatio::Number::Type() { return (AEQ_OBJ_NUMBER); }

std::string aequatio::Number::String() {
  std::stringstream stream;
  std::string out;
  stream << value;
  stream >> out;
  return (out);
}

void aequatio::Number::operator=(const double& in_value) { value = in_value; }
