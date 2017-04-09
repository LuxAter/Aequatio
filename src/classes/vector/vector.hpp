#ifndef AEQUAITO_VECTOR_HPP
#define AEQUAITO_VECTOR_HPP
#include <string>
#include <vector>
#include "../../symbol.hpp"
namespace aequatio {
  class Vector : public Symbol {
   public:
    Vector();
    Vector(int n);
    Vector(std::vector<Symbol*> elements);
    ~Vector();
    int Type();
    std::string String();
    void Sum(Symbol* a, Symbol* b);
    std::vector<Symbol*> vec_terms;
    int length;

   private:
  };
}
#endif
