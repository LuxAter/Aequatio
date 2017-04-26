#ifndef AEQUATIO_MATRIX_FUNCTIONS_HPP
#define AEQUATIO_MATRIX_FUNCTIONS_HPP
#include "../symbol.hpp"
namespace aequatio {
  Symbol Determinant(Symbol a);
  Symbol Trace(Symbol a);
  Symbol Inverse(Symbol a);
  Symbol EchelonForm(Symbol a);
  Symbol Transpose(Symbol a);
}
#endif
