#ifndef AEQUATIO_OBJECT_OBJECT_HPP
#define AEQUATIO_OBJECT_OBJECT_HPP
#include <string>
namespace aequatio {
  class ObjectBase {
   public:
    ObjectBase();
    ObjectBase(const ObjectBase& copy);
    ~ObjectBase();
    virtual int Type();
    virtual std::string String();
   private:
  };
}
#endif
