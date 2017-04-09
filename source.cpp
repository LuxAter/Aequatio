#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

int main(int argc, char const* argv[]) {
  Symbol* num_a = new Number(3.1415);
  Symbol* num_b = new Number(1.2345);
  Symbol* num_c = new Number(1998);
  Symbol* num_d = new Number(10);
  Symbol* vec_a = new Vector({num_a, num_b, num_c});
  Symbol* vec_b = new Vector({num_a, num_b, num_c});
  std::cout << num_a->String() << "," << num_b->String() << ","
            << num_c->String() << "->\n";
  vec_a->Sum(vec_a, vec_b);
  std::cout << vec_b->String() << "\n";
  return 0;
}
