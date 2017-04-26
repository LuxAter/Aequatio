#include <pessum.h>
#include <vector>
#include "../../aequatio.hpp"
#include "../symbol.hpp"
#include "../types.hpp"
#include "vector.hpp"

aequatio::Vector::Vector() { length = 0; }

aequatio::Vector::Vector(int n) {
  length = n;
  vec_terms = std::vector<Symbol>(n, Symbol());
}

aequatio::Vector::Vector(int n, Symbol val){
  length = n;
  vec_terms = std::vector<Symbol>(n, val);
}

aequatio::Vector::Vector(std::vector<Symbol> elements) {
  vec_terms = elements;
  length = vec_terms.size();
}

aequatio::Vector::~Vector() {
  length = int();
  vec_terms.clear();
}

void aequatio::Vector::Append(Symbol element) {
  vec_terms.push_back(element);
  length++;
}

int aequatio::Vector::Type() { return (SY_VECTOR); }

std::string aequatio::Vector::String() {
  std::string vec_str = "<";
  for (int i = 0; i < vec_terms.size(); i++) {
    vec_str += vec_terms[i].String();
    if (i != vec_terms.size() - 1) {
      vec_str += ",";
    }
  }
  vec_str += ">";
  return (vec_str);
}

bool aequatio::operator==(const Vector& a, const Vector& b) {
  bool same = true;
  if (a.length != b.length) {
    same = false;
  }
  for (int i = 0; i < a.length && i < b.length && same == true; i++) {
    if (a.vec_terms[i] != b.vec_terms[i]) {
      same = false;
    }
  }
  return (same);
}

bool aequatio::operator<(const Vector& a, const Vector& b) {
  bool less = true;
  for (int i = 0; i < a.length && i < b.length && less == true; i++) {
    if (a.vec_terms[i] > b.vec_terms[i]) {
      less = false;
    }
  }
  return (less);
}

bool aequatio::operator!=(const Vector& a, const Vector& b) {
  return (!(a == b));
}

bool aequatio::operator>(const Vector& a, const Vector& b) { return (b < a); }

bool aequatio::operator<=(const Vector& a, const Vector& b) {
  return (!(b < a));
}

bool aequatio::operator>=(const Vector& a, const Vector& b) {
  return (!(a < b));
}

aequatio::Vector aequatio::operator+(const Vector& a, const Vector& b) {
  Vector out;
  for (int i = 0; i < b.length || i < a.length; i++) {
    if (i >= a.length) {
      out.Append(b.vec_terms[i]);
    } else if (i >= b.length) {
      out.Append(a.vec_terms[i]);
    } else {
      out.Append(a.vec_terms[i] + b.vec_terms[i]);
    }
  }
  return (out);
}

aequatio::Vector aequatio::operator-(const Vector& a, const Vector& b) {
  Vector out;
  for (int i = 0; i < b.length || i < a.length; i++) {
    if (i >= a.length) {
      out.Append(b.vec_terms[i]);
    } else if (i >= b.length) {
      out.Append(a.vec_terms[i]);
    } else {
      out.Append(a.vec_terms[i] - b.vec_terms[i]);
    }
  }
  return (out);
}

aequatio::Vector aequatio::operator*(const Vector& a, const Vector& b) {
  Vector out;
  for (int i = 0; i < b.length || i < a.length; i++) {
    if (i >= a.length) {
      out.Append(b.vec_terms[i]);
    } else if (i >= b.length) {
      out.Append(a.vec_terms[i]);
    } else {
      out.Append(a.vec_terms[i] * b.vec_terms[i]);
    }
  }
  return (out);
}

aequatio::Vector aequatio::operator/(const Vector& a, const Vector& b) {
  Vector out;
  for (int i = 0; i < b.length || i < a.length; i++) {
    if (i >= a.length) {
      out.Append(b.vec_terms[i]);
    } else if (i >= b.length) {
      out.Append(a.vec_terms[i]);
    } else {
      out.Append(a.vec_terms[i] / b.vec_terms[i]);
    }
  }
  return (out);
}

aequatio::Vector aequatio::operator+(const Vector& a, const Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] + b;
  }
  return (out);
}
aequatio::Vector aequatio::operator-(const Vector& a, const Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] - b;
  }
  return (out);
}
aequatio::Vector aequatio::operator*(const Vector& a, const Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] * b;
  }
  return (out);
}
aequatio::Vector aequatio::operator/(const Vector& a, const Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] / b;
  }
  return (out);
}
