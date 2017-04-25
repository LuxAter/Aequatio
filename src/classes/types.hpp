#ifndef AEQUATIO_TYPES_HPP
#define AEQUATIO_TYPES_HPP
#include <string>
namespace aequatio {
  enum SYMBOL_TYPES { SY_NONE, SY_NUMBER, SY_VECTOR, SY_MATRIX };
  std::string SymbolName(int type);
}
#endif
