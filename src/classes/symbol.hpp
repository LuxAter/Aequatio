#ifndef AEQUATIO_SYMBOL_HPP
#define AEQUATIO_SYMBOL_HPP
#include <memory>
#include <string>
#include <vector>
#include "base.hpp"
namespace aequatio {
  class Symbol {
   public:
    Symbol();
    Symbol(double val);
    Symbol(std::vector<Symbol> val);
    Symbol(std::string str);
    ~Symbol();
    int Type();
    std::string String();
    // Base* ptr;
    std::shared_ptr<Base> ptr;

   private:
  };
  Symbol operator+(Symbol& a, Symbol& b);
  Symbol operator-(Symbol& a, Symbol& b);
  Symbol operator*(Symbol& a, Symbol& b);
  Symbol operator/(Symbol& a, Symbol& b);
}
#endif
