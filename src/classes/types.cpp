#include <string>
#include "types.hpp"

std::string aequatio::SymbolName(int type) {
  std::string str = "";
  if (type == SY_NONE) {
    str = "NONE";
  } else if (type == SY_NUMBER) {
    str = "NUMBER";
  } else if (type == SY_VECTOR) {
    str = "VECTOR";
  } else if (type == SY_MATRIX) {
    str = "MATRIX";
  }
  return (str);
}
