#ifndef AEQUAITO_VECTOR_HPP
#define AEQUAITO_VECTOR_HPP
#include <vector>
#include "../../symbol.hpp"
namespace aequatio {
  class Vector : public Symbol {
   public:
    Vector();
    Vector(std::vector<Symbol*> elements);
    ~Vector();

   private:
    std::vector<Symbol*> vec_terms;
  };
}
#endif
