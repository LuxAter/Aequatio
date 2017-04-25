#include <pessum.h>
#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

struct temp {
  temp() { val = 0; }
  temp(int v) { val = v; }
  int val;
};
temp operator+(const temp& a, const temp& b) {
  temp sum;
  sum = a.val + b.val;
  return (sum);
}

void Handle(std::pair<int, std::string> entry) {
  if (entry.first == pessum::ERROR) {
    system("setterm -fore red");
  } else if (entry.first == pessum::WARNING) {
    system("setterm -fore yellow");
  } else if (entry.first == pessum::TRACE) {
    system("setterm -fore cyan");
  }
  std::cout << entry.second << "\n";
  system("setterm -fore white");
}

int main(int argc, char const* argv[]) {
  pessum::SetLogHandle(Handle);
  Symbol a(1);
  Symbol b(2);
  Symbol c(3);
  Symbol d(0);
  Symbol veca({a, b, c});
  Symbol vecb({b, c, a});
  Symbol vecc({c, a, b});
  Symbol mata({{a, b, c}, {b, c, a}, {c, a, b}});
  Symbol matb({{b, c, a}, {c, a, b}, {a, b, c}});
  Symbol matc({{c, a, b}, {a, b, c}, {b, c, a}});
  std::cout << "a:" << a.String() << "\n";
  std::cout << "b:" << b.String() << "\n";
  std::cout << "c:" << c.String() << "\n";
  std::cout << "d:" << d.String() << "\n";
  std::cout << "vec a:" << veca.String() << "\n";
  std::cout << "vec b:" << vecb.String() << "\n";
  std::cout << "vec c:" << vecc.String() << "\n";
  std::cout << "mat a:" << mata.String() << "\n";
  std::cout << "mat b:" << matb.String() << "\n";
  std::cout << "mat c:" << matc.String() << "\n";
  std::cout << "==========================\n";
  pessum::SaveLog("out.log");
  return 0;
}
