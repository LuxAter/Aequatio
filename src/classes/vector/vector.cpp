#include <vector>
#include "../../symbol.hpp"
#include "vector.hpp"

aequatio::Vector::Vector() {}

aequatio::Vector::Vector(std::vector<Symbol*> elements) {
  vec_terms = elements;
}

aequatio::Vector::~Vector() { vec_terms.clear(); }

int aequatio::Vector::Type(){
  return(SYMBOL_VECTOR);
}

std::string aequatio::Vector::String(){
  std::string vec_str = "<";
  for(int i = 0; i < vec_terms.size(); i++){
    vec_str += vec_terms[i]->String();
    if(i != vec_terms.size() - 1){
      vec_str += ",";
    }
  }
  vec_str += ">";
  return(vec_str);
}
