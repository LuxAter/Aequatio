#include "vector_functions.hpp"
#include "../class_headers.hpp"

aequatio::Symbol aequatio::Dot(aequatio::Symbol a, aequatio::Symbol b){
  int type_a = a.Type(), type_b = b.Type();
  Symbol dot;
  if(type_a == SY_VECTOR && type_b == SY_VECTOR){
    Symbol c = a * b;
    Vector vec_c = *std::dynamic_pointer_cast<Vector>(c.ptr);
    if(vec_c.length > 0){
      dot = vec_c.vec_terms[0];
    }
    for(int i = 1; i < vec_c.length; i++){
      dot = dot + vec_c.vec_terms[i];
    }
  }
  return(dot);
}
