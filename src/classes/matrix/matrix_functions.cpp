#include <pessum.h>
#include "../symbol.hpp"
#include "../types.hpp"
#include "matrix.hpp"
#include <iostream>
#include "matrix_functions.hpp"

aequatio::Symbol aequatio::Determinant(aequatio::Symbol a) {
  int type = a.Type();
  Symbol det;
  if (type == SY_MATRIX) {
    Matrix mat = *std::dynamic_pointer_cast<Matrix>(a.ptr);
    if (mat.rows == 2 && mat.cols == 2) {
      det = (mat.mat_terms[0][0] * mat.mat_terms[1][1]) - (mat.mat_terms[1][0] * mat.mat_terms[0][1]);
    } else if (mat.rows == mat.cols) {
      for (int i = 0; i < mat.cols; i++) {
        std::vector<std::vector<Symbol>> sub_mat_terms(mat.rows - 1, std::vector<Symbol>(mat.cols - 1, Symbol()));
        for(int j = 1; j < mat.rows; j++){
          int sub_k = 0;
          for(int k = 0; k < mat.cols; k++){
            if(k != i){
              sub_mat_terms[j-1][sub_k] = mat.mat_terms[j][k];
              sub_k++;
            }
          }
        }
        Symbol sub_matrix(sub_mat_terms);
        std::cout << sub_matrix.String() << "\n";
        if(det.Type() == 0){
          det = mat.mat_terms[0][i] * Determinant(sub_matrix);
        } else{
          det = det + (mat.mat_terms[0][i] * Determinant(sub_matrix));
        }
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
