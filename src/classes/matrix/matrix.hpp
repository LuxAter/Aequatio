#ifndef AEQUATIO_MATRIX_HPP
#define AEQUATIO_MATRIX_HPP
#include <string>
#include <vector>
#include "../base.hpp"
#include "../symbol.hpp"
#include "../vector/vector.hpp"
namespace aequatio {
  class Matrix : public Base {
   public:
    Matrix();
    Matrix(int n, int m);
    Matrix(std::vector<std::vector<Symbol>> elements);
    ~Matrix();
    int Type();
    std::string String();
    std::vector<std::vector<Symbol>> mat_terms;
    int rows, cols;

   private:
  };
  // Matrix Matrix
  Matrix operator+(Matrix& a, Matrix& b);
  Matrix operator-(Matrix& a, Matrix& b);
  Matrix operator*(Matrix& a, Matrix& b);
  Matrix operator/(Matrix& a, Matrix& b);
  // Matrix Vector
  Matrix operator+(Matrix& a, Vector& b);
  Matrix operator-(Matrix& a, Vector& b);
  Matrix operator*(Matrix& a, Vector& b);
  Matrix operator/(Matrix& a, Vector& b);
  // Matrix Other
  Matrix operator+(Matrix& a, Symbol& b);
  Matrix operator-(Matrix& a, Symbol& b);
  Matrix operator*(Matrix& a, Symbol& b);
  Matrix operator/(Matrix& a, Symbol& b);
}
#endif