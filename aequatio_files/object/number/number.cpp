#include <sstream>
#include "../object.hpp"
#include "../types.hpp"
#include "number.hpp"

aequatio::Number::Number() { value = double(); }

aequatio::Number::Number(double in_value) { value = in_value; }

int aequatio::Number::Type() { return (AEQ_OBJ_NUMBER); }

std::string aequatio::Number::String() {
  std::stringstream stream;
  std::string out;
  stream << value;
  stream >> out;
  return (out);
}
