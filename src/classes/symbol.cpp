#include <pessum.h>
#include <memory>
#include <string>
#include "class_headers.hpp"
#include "symbol.hpp"

aequatio::Symbol::Symbol() {}

aequatio::Symbol::~Symbol() {}

aequatio::Symbol::Symbol(double val) {
  ptr = std::make_shared<Number>(Number(val));
}

aequatio::Symbol::Symbol(std::vector<Symbol> val) {
  ptr = std::make_shared<Vector>(Vector(val));
}

aequatio::Symbol::Symbol(std::string str) {}

int aequatio::Symbol::Type() {
  if (ptr != NULL) {
    return (ptr->Type());
  } else {
    return (SY_NONE);
  }
}

std::string aequatio::Symbol::String() {
  if (ptr != NULL) {
    return (ptr->String());
  } else {
    return ("(null)");
  }
}

aequatio::Symbol aequatio::operator+(Symbol& a, Symbol& b) {
  Symbol sum;
  int type_a = a.Type(), type_b = b.Type();
  if (type_a == SY_NUMBER && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Number>(*std::dynamic_pointer_cast<Number>(a.ptr) +
                                 *std::dynamic_pointer_cast<Number>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) +
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) + b);
  } else if (type_a == SY_NUMBER && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(b.ptr) + a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator acepting type %i and type %i symbols",
                "Symbol/operator+", '+', type_a, type_b);
  }
  return (sum);
}

aequatio::Symbol aequatio::operator-(Symbol& a, Symbol& b) {
  Symbol sum;
  int type_a = a.Type(), type_b = b.Type();
  if (type_a == SY_NUMBER && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Number>(*std::dynamic_pointer_cast<Number>(a.ptr) -
                                 *std::dynamic_pointer_cast<Number>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) -
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) - b);
  } else if (type_a == SY_NUMBER && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(b.ptr) - a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator acepting type %i and type %i symbols",
                "Symbol/operator-", '-', type_a, type_b);
  }
  return (sum);
}

aequatio::Symbol aequatio::operator*(Symbol& a, Symbol& b) {
  Symbol sum;
  int type_a = a.Type(), type_b = b.Type();
  if (type_a == SY_NUMBER && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Number>(*std::dynamic_pointer_cast<Number>(a.ptr) *
                                 *std::dynamic_pointer_cast<Number>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) *
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) * b);
  } else if (type_a == SY_NUMBER && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(b.ptr) * a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator acepting type %i and type %i symbols",
                "Symbol/operator*", '*', type_a, type_b);
  }
  return (sum);
}

aequatio::Symbol aequatio::operator/(Symbol& a, Symbol& b) {
  Symbol sum;
  int type_a = a.Type(), type_b = b.Type();
  if (type_a == SY_NUMBER && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Number>(*std::dynamic_pointer_cast<Number>(a.ptr) /
                                 *std::dynamic_pointer_cast<Number>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) /
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(a.ptr) / b);
  } else if (type_a == SY_NUMBER && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Vector>(*std::dynamic_pointer_cast<Vector>(b.ptr) / a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator acepting type %i and type %i symbols",
                "Symbol/operator/", '/', type_a, type_b);
  }
  return (sum);
}
