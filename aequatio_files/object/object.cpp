#include <string>
#include "object.hpp"
#include "types.hpp"

aequatio::ObjectBase::ObjectBase() {}

int aequatio::ObjectBase::Type() { return (AEQ_OBJ_NONE); }

std::string aequatio::ObjectBase::String() { return ("(null)"); }
