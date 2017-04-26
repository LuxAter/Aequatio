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
    Matrix(int n, int m, Symbol val);
    Matrix(std::vector<std::vector<Symbol>> elements);
    ~Matrix();
    int Type();
    std::string String();
    std::vector<std::vector<Symbol>> mat_terms;
    int rows, cols;

   private:
  };
  //Boolian Operators
  bool operator==(const Matrix& a, const Matrix& b);
  bool operator<(const Matrix& a, const Matrix& b);
  bool operator!=(const Matrix& a, const Matrix& b);
  bool operator>(const Matrix& a, const Matrix& b);
  bool operator<=(const Matrix& a, const Matrix& b);
  bool operator>=(const Matrix& a, const Matrix& b);
  // Matrix Matrix
  Matrix operator+(const Matrix& a, const Matrix& b);
  Matrix operator-(const Matrix& a, const Matrix& b);
  Matrix operator*(const Matrix& a, const Matrix& b);
  Matrix operator/(const Matrix& a, const Matrix& b);
  // Matrix Vector
  Matrix operator+(const Matrix& a, const Vector& b);
  Matrix operator-(const Matrix& a, const Vector& b);
  Matrix operator*(const Matrix& a, const Vector& b);
  Matrix operator/(const Matrix& a, const Vector& b);
  // Matrix Other
  Matrix operator+(const Matrix& a, const Symbol& b);
  Matrix operator-(const Matrix& a, const Symbol& b);
  Matrix operator*(const Matrix& a, const Symbol& b);
  Matrix operator/(const Matrix& a, const Symbol& b);
}
#endif
