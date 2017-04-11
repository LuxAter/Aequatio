#include <pessum.h>
#include <vector>
#include "../../aequatio.hpp"
#include "../class_headers.hpp"
#include "vector.hpp"

aequatio::Vector::Vector() { length = 0; }

aequatio::Vector::Vector(int n) {
  length = n;
  vec_terms = std::vector<Symbol>(n, Symbol());
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

aequatio::Vector aequatio::operator+(Vector& a, Vector& b) {
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

aequatio::Vector aequatio::operator-(Vector& a, Vector& b) {
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

aequatio::Vector aequatio::operator*(Vector& a, Vector& b) {
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

aequatio::Vector aequatio::operator/(Vector& a, Vector& b) {
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

aequatio::Vector aequatio::operator+(Vector& a, Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] + b;
  }
  return (out);
}
aequatio::Vector aequatio::operator-(Vector& a, Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] - b;
  }
  return (out);
}
aequatio::Vector aequatio::operator*(Vector& a, Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = out.vec_terms[i] * b;
  }
  return (out);
}
aequatio::Vector aequatio::operator/(Vector& a, Symbol& b) {
  Vector out = a;
  for (int i = 0; i < out.length; i++) {
    out.vec_terms[i] = b / out.vec_terms[i];
  }
  return (out);
}
