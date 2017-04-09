#include <string>
#include "../../symbol.hpp"
#include "number.hpp"

aequatio::Number::Number() {}

aequatio::Number::Number(double in_val) { val = in_val; }

aequatio::Number::~Number() {}

int aequatio::Number::Type() { return (SYMBOL_NUMBER); }

std::string aequatio::Number::String() { return (std::to_string(val)); }

void aequatio::Number::Sum(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_NUMBER && type_b == SYMBOL_NUMBER) {
    Number* num_a = dynamic_cast<Number*>(a);
    Number* num_b = dynamic_cast<Number*>(b);
    val = num_a->val + num_b->val;
  }
}
