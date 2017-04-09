#ifndef AEQUATIO_SYMBOL_HPP
#define AEQUATIO_SYMBOL_HPP
#include <string>
namespace aequatio {
  enum SYMBOL_TYPES { SYMBOL_NONE, SYMBOL_NUMBER, SYMBOL_VECTOR };
  class Symbol {
   public:
    Symbol();
    ~Symbol();
    virtual int Type();
    virtual std::string String();
    virtual void Sum(Symbol* a, Symbol* b);
    virtual void Diff(Symbol* a, Symbol* b);
    virtual void Prod(Symbol* a, Symbol* b);
    virtual void Quot(Symbol* a, Symbol* b);

   private:
  };
}
#endif
