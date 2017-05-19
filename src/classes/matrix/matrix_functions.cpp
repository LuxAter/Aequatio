#include <math.h>
#include <pessum.h>
#include <iostream>
#include "../number/number.hpp"
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
      det = (mat.mat_terms[0][0] * mat.mat_terms[1][1]) -
            (mat.mat_terms[1][0] * mat.mat_terms[0][1]);
    } else if (mat.rows == mat.cols) {
      for (int i = 0; i < mat.cols; i++) {
        std::vector<std::vector<Symbol>> sub_mat_terms(
            mat.rows - 1, std::vector<Symbol>(mat.cols - 1, Symbol()));
        for (int j = 1; j < mat.rows; j++) {
          int sub_k = 0;
          for (int k = 0; k < mat.cols; k++) {
            if (k != i) {
              sub_mat_terms[j - 1][sub_k] = mat.mat_terms[j][k];
              sub_k++;
            }
          }
        }
        Symbol sub_matrix(sub_mat_terms);
        if (det.Type() == 0) {
          det = mat.mat_terms[0][i] * Determinant(sub_matrix);
        } else {
          det = det + (Symbol(pow(-1, i)) * mat.mat_terms[0][i] *
                       Determinant(sub_matrix));
        }
      }
    } else {
      pessum::Log(pessum::WARNING, "Matrix must by square not %ix%i",
                  "matrix/matrix_functions/Determinant", mat.rows, mat.cols);
    }
  } else {
    pessum::Log(pessum::WARNING, "Symbol must be of type %s not %s",
                "matrix/matrix_functions/Determinant",
                SymbolName(SY_MATRIX).c_str(), SymbolName(type).c_str());
  }
  return (det);
}

aequatio::Symbol aequatio::Trace(aequatio::Symbol a) {
  int type = a.Type();
  Symbol trace;
  if (type == SY_MATRIX) {
    Matrix mat = *std::dynamic_pointer_cast<Matrix>(a.ptr);
    for (int i = 0; i < mat.rows && i < mat.cols; i++) {
      if (trace.Type() == 0) {
        trace = mat.mat_terms[i][i];
      } else {
        trace = trace + mat.mat_terms[i][i];
      }
    }
  } else {
    pessum::Log(pessum::WARNING, "Symbol must be of type %s not %s",
                "matrix/matrix_functions/Trace", SymbolName(SY_MATRIX).c_str(),
                SymbolName(type).c_str());
  }
  return (trace);
}

aequatio::Symbol aequatio::Inverse(aequatio::Symbol a) {
  int type = a.Type();
  Symbol inv;
  if (type == SY_MATRIX) {
    Matrix mat = *std::dynamic_pointer_cast<Matrix>(a.ptr);
    if (Determinant(a) == 0) {
      pessum::Log(pessum::WARNING,
                  "The inverse does not exist as the determinant is %s",
                  "matrix/matrix_functions/Inverse", "0");
    } else {
      Symbol det = Determinant(a);
      std::vector<std::vector<Symbol>> inverse_terms(
          mat.rows, std::vector<Symbol>(mat.cols, Symbol()));
      for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
          std::vector<std::vector<Symbol>> sub_matrix_terms(
              mat.rows - 1, std::vector<Symbol>(mat.cols - 1, Symbol(0)));
          int sub_row = 0;
          for (int k = 0; k < mat.rows; k++) {
            int sub_col = 0;
            if (k != i) {
              for (int l = 0; l < mat.cols; l++) {
                if (l != j) {
                  sub_matrix_terms[sub_row][sub_col] = mat.mat_terms[k][l];
                  sub_col++;
                }
              }
              sub_row++;
            }
          }
          Symbol sub_matrix(sub_matrix_terms);
          inverse_terms[i][j] = (Symbol(pow(-1, i)) * Symbol(pow(-1, j))) *
                                Determinant(sub_matrix);
        }
      }
      inv = Transpose(Symbol(inverse_terms));
      inv = inv / det;
    }
  } else {
    pessum::Log(pessum::WARNING, "Symbol must be of type %s not %s",
                "matrix/matrix_functions/Determinant",
                SymbolName(SY_MATRIX).c_str(), SymbolName(type).c_str());
  }
  return (inv);
}

aequatio::Symbol aequatio::RowEchelonForm(aequatio::Symbol a) {
  int type = a.Type();
  Symbol ech;
  if (type == SY_MATRIX) {
    Matrix mat = *std::dynamic_pointer_cast<Matrix>(a.ptr);
    std::vector<std::vector<Symbol>> ref(mat.rows, std::vector<Symbol>(mat.cols, Symbol()));
  }
  return (ech);
}

aequatio::Symbol aequatio::Transpose(aequatio::Symbol a){
  int type = a.Type();
  Symbol transpose;
  if(type == SY_MATRIX){
    Matrix mat = *std::dynamic_pointer_cast<Matrix>(a.ptr);
    std::vector<std::vector<Symbol>> transpose_terms(
        mat.cols, std::vector<Symbol>(mat.rows, Symbol()));
    for(int i = 0; i < mat.rows; i++){
      for(int j = 0; j < mat.cols; j++){
        transpose_terms[j][i] = mat.mat_terms[i][j];
      }
    }
    transpose = Symbol(transpose_terms);
  }else{
    pessum::Log(pessum::WARNING, "Symbol must be of type %s not %s",
                "matrix/matrix_functions/Transpose",
                SymbolName(SY_MATRIX).c_str(), SymbolName(type).c_str());
  }
  return(transpose);
}
