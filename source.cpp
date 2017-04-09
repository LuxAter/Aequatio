#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

void FullHandle(std::pair<int, std::string> entry){
  if(entry.first == L_ERROR){
    system("setterm -fore red");
  } else if(entry.first == L_WARNING){
    system("setterm -fore yellow");
  } else if(entry.first == L_TRACE){
    system("setterm -fore cyan");
  }
  std::cout << entry.second << "\n";
  system("setterm -fore white");
}

void handle(std::string str) { std::cout << str << "\n"; }

int main(int argc, char const* argv[]) {
  SetLogHandle(handle);
  SetLogHandle(FullHandle);
  Symbol* num_a = new Number(3.1415);
  Symbol* num_b = new Number(1.2345);
  Symbol* num_c = new Number(1998);
  Symbol* vec_a = new Vector({num_a, num_b, num_c});
  std::cout << num_a->String() << "\n";
  std::cout << num_b->String() << "\n";
  std::cout << num_c->String() << "\n";
  std::cout << vec_a->String() << "\n";
  std::cout << "==========================\n";
  Symbol* tot = new Vector();
  Total(tot, vec_a);
  num_a->Sum(num_a, vec_a);
  std::cout << tot->String() << "\n";
  SaveLog();
  return 0;
}
