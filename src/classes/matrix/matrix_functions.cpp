#include <pessum.h>
#include "../symbol.hpp"
#include "../types.hpp"
#include "matrix.hpp"
#include "matrix_functions.hpp"

aequatio::Symbol aequatio::Determinant(aequatio::Symbol a) {
  int type = a.Type();
  Symbol det;
  if (type == SY_MATRIX) {
    Matrix mat = *std::dynamic_pointer_cast<Matrix>(a.ptr);
    if (mat.rows == 2 && mat.cols == 2) {
      det = (mat.mat_terms[0][0] * mat.mat_terms[1][1]);
      Symbol second = (mat.mat_terms[1][0] * mat.mat_terms[0][1]);
      det = det - second;
    } else if (mat.rows == mat.cols) {
      for (int i = 0; i < mat.cols; i++) {
        Symbol sub_matrix;
        det = det + (mat.mat_terms[0][i] * Determinant(sub_matrix));
      }
    } else {
      pessum::Log(pessum::WARNING, "Matrix must by square not %ix%i",
                  "matrix/matrix_functions/Determinant", mat.rows, mat.cols);
    }
  } else {
    pessum::Log(pessum::WARNING, "Symbol must be of type %i not %i",
                "matrix/matrix_functions/Determinant", SY_MATRIX, type);
  }
  return (det);
}

aequatio::Symbol aequatio::Trace(aequatio::Symbol a) {
  int type = a.Type();
  Symbol trace;
  if (type == SY_MATRIX) {
  }
  return (trace);
}

aequatio::Symbol aequatio::Inverse(aequatio::Symbol a) {
  int type = a.Type();
  Symbol inv;
  if (type == SY_MATRIX) {
  }
  return (inv);
}

aequatio::Symbol aequatio::EchelonForm(aequatio::Symbol a) {
  int type = a.Type();
  Symbol ech;
  if (type == SY_MATRIX) {
  }
  return (ech);
}
