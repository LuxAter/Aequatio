#ifndef AEQUATIO_OBJECT_NUMBER_NUMBER_HPP
#define AEQUATIO_OBJECT_NUMBER_NUMBER_HPP
#include <string>
#include "../object.hpp"
namespace aequatio {
  class Number : public ObjectBase {
   public:
    Number();
    Number(double in_value);
    int Type();
    std::string String();
    double value;

   private:
  };
}
#endif
