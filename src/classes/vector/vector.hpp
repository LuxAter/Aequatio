#ifndef AEQUAITO_VECTOR_HPP
#define AEQUAITO_VECTOR_HPP
#include <string>
#include <vector>
#include "../base.hpp"
#include "../symbol.hpp"
namespace aequatio {
  class Vector : public Base {
   public:
    Vector();
    Vector(int n);
    Vector(std::vector<Symbol> elements);
    ~Vector();
    void Append(Symbol element);
    int Type();
    std::string String();
    std::vector<Symbol> vec_terms;
    int length;

   private:
  };
  // Vector Vector
  Vector operator+(const Vector& a, const Vector& b);
  Vector operator-(const Vector& a, const Vector& b);
  Vector operator*(const Vector& a, const Vector& b);
  Vector operator/(const Vector& a, const Vector& b);
  // Vector Other
  Vector operator+(const Vector& a, const Symbol& b);
  Vector operator-(const Vector& a, const Symbol& b);
  Vector operator*(const Vector& a, const Symbol& b);
  Vector operator/(const Vector& a, const Symbol& b);
}
#endif
