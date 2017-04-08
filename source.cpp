#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

int main(int argc, char const* argv[]) {
  Symbol* num_a = new Number(3.1415);
  Symbol* num_b = new Number(1.2345);
  Symbol* num_c = new Number(1998);
  Symbol* vec = new Vector({num_a, num_b, num_c});
  std::cout << num_a->String() << "," << num_b->String() << "," << num_c->String() << "->\n";
  std::cout << vec->String() << "\n";
  return 0;
}
