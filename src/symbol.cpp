#include <math.h>
#include <iostream>
#include <string>
#include "symbol.hpp"

aequatio::Symbol::Symbol() {}

aequatio::Symbol::~Symbol() {}

int aequatio::Symbol::Type() { return (SYMBOL_NONE); }

std::string aequatio::Symbol::String() { return ("(null)"); }

void aequatio::Symbol::Sum(Symbol* a, Symbol* b) {}
