#include <math.h>
#include <iostream>
#include <string>
#include "base.hpp"

aequatio::Base::Base() {}

aequatio::Base::~Base() {}

int aequatio::Base::Type() { return (SY_NONE); }

std::string aequatio::Base::String() { return ("(null)"); }
