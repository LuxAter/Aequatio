#ifndef AEQUATIO_SYMBOL_HPP
#define AEQUATIO_SYMBOL_HPP
#include <string>
namespace aequatio {
  enum SYMBOL_TYPES { SYMBOL_NONE, SYMBOL_NUMBER, SYMBOL_VECTOR };
  // enum SY_TYPE { T_NONE, T_VALUE, T_OP, T_FUNC, T_VAR, T_PAREN, T_OTHER };
  // enum SY_ASSOCIATION { A_NONE, A_LEFT, A_RIGHT };
  // enum VAL_TYPE { V_NONE, V_NUM, V_VEC, V_MATRIX };
  // struct Symbol {
  //  public:
  //   Symbol();
  //   Symbol(std::string str);
  //   Symbol(double val);
  //   Symbol(int val);
  //   ~Symbol();
  //   std::string str, alt_str;
  //   int type, assoc, prec, val_type;
  //   double val_double;
  //
  //  private:
  //   int LoadType();
  // };
  class Symbol {
   public:
    Symbol();
    ~Symbol();
    virtual int Type();
    virtual std::string String();

   private:
  };
  // Symbol Pow(const Symbol& a, const Symbol& b);
  // Symbol operator+(const Symbol& a, const Symbol& b);
  // Symbol operator-(const Symbol& a, const Symbol& b);
  // Symbol operator*(const Symbol& a, const Symbol& b);
  // Symbol operator/(const Symbol& a, const Symbol& b);
}
#endif
