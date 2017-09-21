#include <iostream>

struct all {
  enum { CHAR, INT, DOUBLE } tags;
  union {
    char c;
    int i;
    double d;
  };
}

int main(int argc, char const* argv[]) {
  // std::cout << "v:" << v << "\n";
  return 0;
}
