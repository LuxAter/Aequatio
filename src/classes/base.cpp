#include <math.h>
#include <iostream>
#include <string>
#include "base.hpp"
#include "types.hpp"

aequatio::Base::Base() {}

aequatio::Base::~Base() {}

int aequatio::Base::Type() { return (SY_NONE); }

std::string aequatio::Base::String() { return ("(null)"); }
