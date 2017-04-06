#ifndef AEQUATIO_MATRIX
#define AEQUATIO_MATRIX
#include <vector>

namespace aequatio {
  template <class _T>
  class Matrix {
   public:
    Matrix() {
      n_rows = 0;
      n_cols = 0;
    }
    Matrix(int rows, int cols){
      n_rows = rows;
      n_cols = cols;
      matrix_data = std::vector<_T>(n_rows * n_cols, _T());
    }
    Matrix(int rows, int cols, std::vector<_T> data){
      n_rows = rows;
      n_cols = cols;
      if(data.size() == rows * cols){
        matrix_data = data;
      }else{
        Log("Incorect number of elements for matrix of %ix%i", n_rows, n_cols);
        matrix_data = std::vector<_T>(n_rows * n_cols, _T());
      }
    }
    ~Matrix() {
      n_rows = int();
      n_cols = int();
      matrix_data.clear();
    }
    _T operator[](int row, int col){
      if(row < n_rows && col < n_cols && row >= 0 && cols >= 0){
        return(matrix_data[(row * n_cols) + col]);
      }else{
        return(_T());
      }
    }
    _T operator[](int element){
      if(element >= 0 && element < n_rows * n_cols){
        return(matrix_data[element]);
      }else{
        return(_T());
    }

   private:
    int n_rows, n_cols;
    std::vector<_T> matrix_data;
  };
}
#endif
