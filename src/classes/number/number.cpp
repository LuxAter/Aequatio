#include "number.hpp"
#include <string>
#include "../../symbol.hpp"

aequatio::Number::Number() {}

aequatio::Number::Number(double in_val) { val = in_val; }

aequatio::Number::~Number() {}

int aequatio::Number::Type() { return (SYMBOL_NUMBER); }

std::string aequatio::Number::String() { return (std::to_string(val)); }
