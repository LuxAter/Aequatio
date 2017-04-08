#include "../../symbol.hpp"
#include "number.hpp"

aequatio::Number::Number() {}

aequatio::Number::Number(double in_val) { val = in_val; }

aequatio::Number::~Number() {}

int aequatio::Number::Type() { return (SYMBOL_NUMBER); }
