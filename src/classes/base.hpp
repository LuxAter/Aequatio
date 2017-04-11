#ifndef AEQUATIO_CLASS_BASE_HPP
#define AEQUATIO_CLASS_BASE_HPP
#include <string>
namespace aequatio {
  enum SYMBOL_TYPES { SY_NONE, SY_NUMBER, SY_VECTOR };
  class Base {
   public:
    Base();
    virtual ~Base();
    virtual int Type();
    virtual std::string String();

   private:
  };
}
#endif
