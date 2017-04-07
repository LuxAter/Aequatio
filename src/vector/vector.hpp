#ifndef AEQUAITO_VECTOR_HPP
#define AEQUAITO_VECTOR_HPP
#include <vector>
namespace aequatio {
  class Vector {
   public:
    Vector();
    Vector(std::vector<double> elements);
    ~Vector();
    double operator[](int n);

   private:
    int length;
    std::vector<double> vec_elements;
  };
  Vector operator+(const Vector& a, const Vector& b);
}
#endif
