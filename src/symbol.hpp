#ifndef AEQUATIO_SYMBOL_HPP
#define AEQUATIO_SYMBOL_HPP
#include <string>
#include "class_headers.hpp"
namespace aequatio {
  enum SY_TYPE { T_NONE, T_VALUE, T_OP, T_FUNC, T_VAR, T_PAREN, T_OTHER };
  enum SY_ASSOCIATION { A_NONE, A_LEFT, A_RIGHT };
  enum VAL_TYPE { V_NONE, V_NUM, V_VEC, V_MATRIX };
  struct Symbol {
   public:
    Symbol();
    Symbol(std::string str);
    Symbol(double val);
    Symbol(int val);
    ~Symbol();
    std::string str, alt_str;
    int type, assoc, prec, val_type;
    double val_double;
    // Vector val_vector;

   private:
    int LoadType();
  };
  Symbol Pow(const Symbol& a, const Symbol& b);
  Symbol operator+(const Symbol& a, const Symbol& b);
  Symbol operator-(const Symbol& a, const Symbol& b);
  Symbol operator*(const Symbol& a, const Symbol& b);
  Symbol operator/(const Symbol& a, const Symbol& b);
}
#endif
