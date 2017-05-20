#ifndef AEQUATIO_OBJECT_NUMBER_NUMBER_HPP
#define AEQUATIO_OBJECT_NUMBER_NUMBER_HPP
#include <string>
#include "../object.hpp"
namespace aequatio {
  class Number : public ObjectBase {
   public:
    Number();
    Number(const Number& copy);
    Number(double in_value);
    ~Number();
    int Type();
    std::string String();
    double value;

   private:
  };
}
#endif
