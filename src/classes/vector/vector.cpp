#include <vector>
#include "../../symbol.hpp"
#include "../class_headers.hpp"
#include "vector.hpp"

aequatio::Vector::Vector() {}

aequatio::Vector::Vector(int n) {
  vec_terms = std::vector<Symbol*>(n, new Symbol);
}

aequatio::Vector::Vector(std::vector<Symbol*> elements) {
  vec_terms = elements;
}

aequatio::Vector::~Vector() { vec_terms.clear(); }

int aequatio::Vector::Type() { return (SYMBOL_VECTOR); }

std::string aequatio::Vector::String() {
  std::string vec_str = "<";
  for (int i = 0; i < vec_terms.size(); i++) {
    vec_str += vec_terms[i]->String();
    if (i != vec_terms.size() - 1) {
      vec_str += ",";
    }
  }
  vec_str += ">";
  return (vec_str);
}

void aequatio::Vector::Sum(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_NUMBER) {
    Vector* vec = dynamic_cast<Vector*>(a);
    Symbol* num = b;
    if (vec == NULL) {
      vec = dynamic_cast<Vector*>(b);
      num = a;
    }
    vec_terms = vec->vec_terms;
    for (int i = 0; i < vec_terms.size(); i++) {
      vec_terms[i]->Sum(vec_terms[i], num);
    }
  } else if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_VECTOR) {
    Vector* vec_a = dynamic_cast<Vector*>(a);
    Vector* vec_b = dynamic_cast<Vector*>(b);
    vec_terms = vec_a->vec_terms;
    for (int i = 0; i < vec_b->vec_terms.size(); i++) {
      if (i < vec_terms.size()) {
        vec_terms[i]->Sum(vec_terms[i], vec_b->vec_terms[i]);
      } else {
        vec_terms.push_back(vec_b->vec_terms[i]);
      }
    }
  }
}

void aequatio::Vector::Diff(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_NUMBER) {
    Vector* vec = dynamic_cast<Vector*>(a);
    Symbol* num = b;
    if (vec == NULL) {
      vec = dynamic_cast<Vector*>(b);
      num = a;
    }
    vec_terms = vec->vec_terms;
    for (int i = 0; i < vec_terms.size(); i++) {
      vec_terms[i]->Diff(vec_terms[i], num);
    }
  } else if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_VECTOR) {
    Vector* vec_a = dynamic_cast<Vector*>(a);
    Vector* vec_b = dynamic_cast<Vector*>(b);
    vec_terms = vec_a->vec_terms;
    for (int i = 0; i < vec_b->vec_terms.size(); i++) {
      if (i < vec_terms.size()) {
        vec_terms[i]->Diff(vec_terms[i], vec_b->vec_terms[i]);
      } else {
        vec_terms.push_back(vec_b->vec_terms[i]);
      }
    }
  }
}

void aequatio::Vector::Prod(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_NUMBER) {
    Vector* vec = dynamic_cast<Vector*>(a);
    Symbol* num = b;
    if (vec == NULL) {
      vec = dynamic_cast<Vector*>(b);
      num = a;
    }
    vec_terms = vec->vec_terms;
    for (int i = 0; i < vec_terms.size(); i++) {
      vec_terms[i]->Prod(vec_terms[i], num);
    }
  } else if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_VECTOR) {
    Vector* vec_a = dynamic_cast<Vector*>(a);
    Vector* vec_b = dynamic_cast<Vector*>(b);
    vec_terms = vec_a->vec_terms;
    for (int i = 0; i < vec_b->vec_terms.size(); i++) {
      if (i < vec_terms.size()) {
        vec_terms[i]->Prod(vec_terms[i], vec_b->vec_terms[i]);
      } else {
        vec_terms.push_back(vec_b->vec_terms[i]);
      }
    }
  }
}

void aequatio::Vector::Quot(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_NUMBER) {
    Vector* vec = dynamic_cast<Vector*>(a);
    Symbol* num = b;
    if (vec == NULL) {
      vec = dynamic_cast<Vector*>(b);
      num = a;
    }
    vec_terms = vec->vec_terms;
    for (int i = 0; i < vec_terms.size(); i++) {
      vec_terms[i]->Quot(vec_terms[i], num);
    }
  } else if (type_a == SYMBOL_VECTOR && type_b == SYMBOL_VECTOR) {
    Vector* vec_a = dynamic_cast<Vector*>(a);
    Vector* vec_b = dynamic_cast<Vector*>(b);
    vec_terms = vec_a->vec_terms;
    for (int i = 0; i < vec_b->vec_terms.size(); i++) {
      if (i < vec_terms.size()) {
        vec_terms[i]->Quot(vec_terms[i], vec_b->vec_terms[i]);
      } else {
        vec_terms.push_back(vec_b->vec_terms[i]);
      }
    }
  }
}
