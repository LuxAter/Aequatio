#include <string>
#include "../../aequatio.hpp"
#include "../../symbol.hpp"
#include "../class_headers.hpp"
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
  } else{
    Log(L_WARNING,
        "There is no sum operation between %i and %i that results in a %i type",
        "Number/Sum", type_a, type_b, SYMBOL_NUMBER);
  }
}

void aequatio::Number::Diff(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_NUMBER && type_b == SYMBOL_NUMBER) {
    Number* num_a = dynamic_cast<Number*>(a);
    Number* num_b = dynamic_cast<Number*>(b);
    val = num_a->val - num_b->val;
  } else{
    Log(L_WARNING,
        "There is no difference operation between %i and %i that results in a %i type",
        "Number/Sum", type_a, type_b, SYMBOL_NUMBER);
  }
}

void aequatio::Number::Prod(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_NUMBER && type_b == SYMBOL_NUMBER) {
    Number* num_a = dynamic_cast<Number*>(a);
    Number* num_b = dynamic_cast<Number*>(b);
    val = num_a->val * num_b->val; 
  } else{
    Log(L_WARNING,
        "There is no product operation between %i and %i that results in a %i type",
        "Number/Sum", type_a, type_b, SYMBOL_NUMBER);
  }
}

void aequatio::Number::Quot(Symbol* a, Symbol* b) {
  int type_a = a->Type(), type_b = b->Type();
  if (type_a == SYMBOL_NUMBER && type_b == SYMBOL_NUMBER) {
    Number* num_a = dynamic_cast<Number*>(a);
    Number* num_b = dynamic_cast<Number*>(b);
    val = num_a->val / num_b->val;
  } else{
    Log(L_WARNING,
        "There is no quotient operation between %i and %i that results in a %i type",
        "Number/Sum", type_a, type_b, SYMBOL_NUMBER);
  }
}

void aequatio::Total(Symbol* ret, Symbol* a) {
  if (ret->Type() != SYMBOL_NUMBER) {
    Log(L_WARNING, "Return symbol must be of type %i not %i", "Total",
        SYMBOL_NUMBER, ret->Type());
  } else {
    Number* ret_num = dynamic_cast<Number*>(ret);
    int type_a = a->Type();
    if (type_a == SYMBOL_NUMBER) {
      Number* num_a = dynamic_cast<Number*>(a);
      ret_num->val = num_a->val;
    } else if (type_a == SYMBOL_VECTOR) {
      Vector* vec_a = dynamic_cast<Vector*>(a);
      ret_num->val = double();
      for (int i = 0; i < vec_a->vec_terms.size(); i++) {
        Number* vec_tot = new Number();
        Total(vec_tot, vec_a->vec_terms[i]);
        ret_num->val += vec_tot->val;
      }
    }
    ret = ret_num;
  }
}
