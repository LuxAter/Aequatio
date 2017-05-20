#ifndef AEQUATIO_OBJECT_COMPLEX_COMPLEX_HPP
#define AEQUATIO_OBJECT_COMPLEX_COMPLEX_HPP
#include <string>
#include "../object.hpp"
namespace aequatio{
  class Complex : public ObjectBase{
    public:
      Complex();
      Complex(const Complex& copy);
      Complex(double in_real, double in_imag);
      ~Complex();
      int Type();
      std::string String();
      double real, imag;
    private:
  };
}
#endif
