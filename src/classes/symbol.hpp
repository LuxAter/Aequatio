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
    Symbol(std::vector<std::vector<Symbol>> val);
    Symbol(std::string str);
    ~Symbol();
    int Type() const;
    std::string String();
    std::shared_ptr<Base> ptr;

   private:
  };
  Symbol operator+(const Symbol& a, const Symbol& b);
  Symbol operator-(const Symbol& a, const Symbol& b);
  Symbol operator*(const Symbol& a, const Symbol& b);
  Symbol operator/(const Symbol& a, const Symbol& b);
  bool operator==(const Symbol& a, const Symbol& b);
  bool operator<(const Symbol& a, const Symbol& b);
  bool operator!=(const Symbol& a, const Symbol& b);
  bool operator>(const Symbol& a, const Symbol& b);
  bool operator<=(const Symbol& a, const Symbol& b);
  bool operator>=(const Symbol& a, const Symbol& b);
}
#endif
