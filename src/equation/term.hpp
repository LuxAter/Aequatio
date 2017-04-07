#ifndef AEQUATIO_TERM_HPP
#define AEQUATIO_TERM_HPP
#include <string>
#include "function.hpp"
namespace aequatio {
  enum TERM_TYPE { T_NONE, T_VALUE, T_OP, T_FUNC, T_VAR, T_PAREN, T_OTHER };
  enum TERM_ASSOCIATION { A_NONE, A_LEFT, A_RIGHT };
  class Term {
   public:
    Term();
    Term(std::string str);
    ~Term();
    std::string str, alt_str;
    int type, assoc, prec;
    double value;

   private:
    int LoadType();
  };
}
#endif
