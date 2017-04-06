#ifndef AEQUATIO_TERM_HPP
#define AEQUATIO_TERM_HPP
#include <string>
namespace aequatio {
  enum TERM_TYPE{
    NONE, FUNC, VAR
  };
  struct Term{
    Term();
    ~Term(();
    std::string term_str;
    int term_type;
    Function term_func;
    double term_value;
  };
}
#endif
