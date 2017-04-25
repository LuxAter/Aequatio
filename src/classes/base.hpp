#ifndef AEQUATIO_CLASS_BASE_HPP
#define AEQUATIO_CLASS_BASE_HPP
#include <string>
namespace aequatio {
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
