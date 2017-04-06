#ifndef AEQUATIO_TERM_HPP
#define AEQUATIO_TERM_HPP
#include <string>
namespace aequatio {
  enum TERM_TYPE {
    TERM_NULL = 0,
    TERM_VALUE = 1,
    TERM_OPERATOR = 2,
    TERM_FUNCTION = 3,
    TERM_VARIABLE = 4,
    TERM_GROUPING = 5
  };
  struct Term {
    Term();
    Term(std::string str);
    ~Term();
    int term_type, term_weight, n_operator_arg;
    std::string term_string;
    double term_value;
  };
}
#endif
