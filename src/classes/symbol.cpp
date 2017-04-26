#include <pessum.h>
#include <memory>
#include <string>
#include "class_headers.hpp"
#include "symbol.hpp"
#include "types.hpp"

aequatio::Symbol::Symbol() {}

aequatio::Symbol::~Symbol() { ptr = NULL; }

aequatio::Symbol::Symbol(double val) {
  ptr = std::make_shared<Number>(Number(val));
}

aequatio::Symbol::Symbol(std::vector<Symbol> val) {
  ptr = std::make_shared<Vector>(Vector(val));
}

aequatio::Symbol::Symbol(std::vector<std::vector<Symbol>> val) {
  ptr = std::make_shared<Matrix>(Matrix(val));
}

aequatio::Symbol::Symbol(std::string str) {}

int aequatio::Symbol::Type() const {
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

aequatio::Symbol aequatio::operator+(const Symbol& a, const Symbol& b) {
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
  } else if (type_a == SY_MATRIX && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) +
                                 *std::dynamic_pointer_cast<Matrix>(b.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) +
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) +
                                 *std::dynamic_pointer_cast<Vector>(a.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) + b);
  } else if (type_a == SY_NUMBER && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) + a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator accepting type %s and type %s symbols",
                "symbol/operator+", '+', SymbolName(type_a).c_str(),
                SymbolName(type_b).c_str());
  }
  return (sum);
}

aequatio::Symbol aequatio::operator-(const Symbol& a, const Symbol& b) {
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
  } else if (type_a == SY_MATRIX && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) -
                                 *std::dynamic_pointer_cast<Matrix>(b.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) -
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) -
                                 *std::dynamic_pointer_cast<Vector>(a.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) - b);
  } else if (type_a == SY_NUMBER && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) - a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator accepting type %s and type %s symbols",
                "symbol/operator-", '-', SymbolName(type_a).c_str(),
                SymbolName(type_b).c_str());
  }
  return (sum);
}

aequatio::Symbol aequatio::operator*(const Symbol& a, const Symbol& b) {
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
  } else if (type_a == SY_MATRIX && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) *
                                 *std::dynamic_pointer_cast<Matrix>(b.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) *
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) *
                                 *std::dynamic_pointer_cast<Vector>(a.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) * b);
  } else if (type_a == SY_NUMBER && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) * a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator accepting type %s and type %s symbols",
                "symbol/operator*", '*', SymbolName(type_a).c_str(),
                SymbolName(type_b).c_str());
  }
  return (sum);
}

aequatio::Symbol aequatio::operator/(const Symbol& a, const Symbol& b) {
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
  } else if (type_a == SY_MATRIX && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) /
                                 *std::dynamic_pointer_cast<Matrix>(b.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_VECTOR) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) /
                                 *std::dynamic_pointer_cast<Vector>(b.ptr));
  } else if (type_a == SY_VECTOR && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) /
                                 *std::dynamic_pointer_cast<Vector>(a.ptr));
  } else if (type_a == SY_MATRIX && type_b == SY_NUMBER) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(a.ptr) / b);
  } else if (type_a == SY_NUMBER && type_b == SY_MATRIX) {
    sum.ptr =
        std::make_shared<Matrix>(*std::dynamic_pointer_cast<Matrix>(b.ptr) / a);
  } else {
    pessum::Log(pessum::WARNING,
                "No %c operator accepting type %s and type %s symbols",
                "symbol/operator/", '/', SymbolName(type_a).c_str(),
                SymbolName(type_b).c_str());
  }
  return (sum);
}

bool aequatio::operator==(const Symbol& a, const Symbol& b) {
  int type_a = a.Type(), type_b = b.Type();
  if (type_a != type_b) {
    return (false);
  } else {
    if (type_a == SY_NUMBER) {
      return (*std::dynamic_pointer_cast<Number>(a.ptr) ==
              *std::dynamic_pointer_cast<Number>(b.ptr));
    } else if (type_a == SY_VECTOR) {
      return (*std::dynamic_pointer_cast<Vector>(a.ptr) ==
              *std::dynamic_pointer_cast<Vector>(b.ptr));
    } else if(type_a == SY_MATRIX){
      return (*std::dynamic_pointer_cast<Matrix>(a.ptr) ==
              *std::dynamic_pointer_cast<Matrix>(b.ptr));
    }
  }
  return (false);
}

bool aequatio::operator<(const Symbol& a, const Symbol& b) {
  int type_a = a.Type(), type_b = b.Type();
  if (type_a < type_b) {
    return (true);
  } else {
    if (type_a == SY_NUMBER) {
      return (*std::dynamic_pointer_cast<Number>(a.ptr) <
              *std::dynamic_pointer_cast<Number>(b.ptr));
    } else if(type_a == SY_VECTOR){
      return (*std::dynamic_pointer_cast<Vector>(a.ptr) <
              *std::dynamic_pointer_cast<Vector>(b.ptr));
    } else if(type_a == SY_MATRIX){
      return (*std::dynamic_pointer_cast<Matrix>(a.ptr) <
              *std::dynamic_pointer_cast<Matrix>(b.ptr));
    }
  }
  return (false);
}

bool aequatio::operator!=(const Symbol& a, const Symbol& b) {
  return (!(a == b));
}

bool aequatio::operator>(const Symbol& a, const Symbol& b) { return (b > a); }

bool aequatio::operator<=(const Symbol& a, const Symbol& b) {
  return (!(b < a));
}

bool aequatio::operator>=(const Symbol& a, const Symbol& b) {
  return (!(a < b));
}

bool aequatio::operator==(const Symbol& a, const int& b){
  int type = a.Type();
  Symbol sy_b;
  if(type == SY_NONE){
  }else if(type == SY_NUMBER){
    sy_b = Symbol(b);
  }else if(type == SY_VECTOR){
    sy_b.ptr = std::make_shared<Vector>(Vector(std::dynamic_pointer_cast<Vector>(a.ptr)->length,b));
  }else if(type == SY_MATRIX){
    sy_b.ptr = std::make_shared<Matrix>(Matrix(std::dynamic_pointer_cast<Matrix>(a.ptr)->rows, std::dynamic_pointer_cast<Matrix>(a.ptr)->cols, Symbol(b)));
  }
  return(a == sy_b);
}

bool aequatio::operator<(const Symbol& a, const int& b){
  int type = a.Type();
  Symbol sy_b; 
  if(type == SY_NONE){
  }else if(type == SY_NUMBER){
    sy_b = Symbol(b);
  }else if(type == SY_VECTOR){
    sy_b.ptr = std::make_shared<Vector>(Vector(std::dynamic_pointer_cast<Vector>(a.ptr)->length,b));
  }else if(type == SY_MATRIX){
    sy_b.ptr = std::make_shared<Matrix>(Matrix(std::dynamic_pointer_cast<Matrix>(a.ptr)->rows, std::dynamic_pointer_cast<Matrix>(a.ptr)->cols, Symbol(b)));
  }
  return(a < sy_b);
}

bool aequatio::operator!=(const Symbol& a, const int& b){
  return(!(a==b));
}

bool aequatio::operator>(const Symbol& a, const int& b){
  return(b > a);
}

bool aequatio::operator<=(const Symbol& a, const int& b){
  return(!(b < a));
}

bool aequatio::operator>=(const Symbol& a, const int& b){
  return(!(a < b));
}
