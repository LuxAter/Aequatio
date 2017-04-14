#include <pessum.h>
#include <iostream>
#include "src/aequatio_headers.hpp"

using namespace aequatio;

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
  std::cout << "a:" << a.String() << "\n";
  std::cout << "b:" << b.String() << "\n";
  std::cout << "c:" << c.String() << "\n";
  std::cout << "d:" << d.String() << "\n";
  std::cout << "vec a:" << veca.String() << "\n";
  std::cout << "vec b:" << vecb.String() << "\n";
  std::cout << "vec c:" << vecc.String() << "\n";
  std::cout << "==========================\n";
  Symbol dot = Dot(veca, vecb);
  std::cout << "<" << veca.String() << "," << vecb.String() << "> = " << dot.String()  << "\n";
  pessum::SaveLog("out.log");
  return 0;
}
