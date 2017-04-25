#include <pessum.h>
#include "../symbol.hpp"
#include "../types.hpp"
#include "vector.hpp"
#include "vector_functions.hpp"

aequatio::Symbol aequatio::DotProduct(aequatio::Symbol a, aequatio::Symbol b) {
  int type_a = a.Type(), type_b = b.Type();
  Symbol dot;
  if (type_a == SY_VECTOR && type_b == SY_VECTOR) {
    Symbol c = a * b;
    Vector vec_c = *std::dynamic_pointer_cast<Vector>(c.ptr);
    if (vec_c.length > 0) {
      dot = vec_c.vec_terms[0];
    }
    for (int i = 1; i < vec_c.length; i++) {
      dot = dot + vec_c.vec_terms[i];
    }
  } else {
    pessum::Log(pessum::WARNING, "No Dot Product for type %i and %i",
                "vector/vector_functions/DotProduct", type_a, type_b);
  }
  return (dot);
}
