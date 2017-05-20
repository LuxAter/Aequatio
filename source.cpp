#include <pessum.h>
#include <iostream>
#include <memory>
#include "aequatio_files/aequatio_headers.hpp"

// using namespace aequatio;

// struct temp {
//   temp() { val = 0; }
//   temp(int v) { val = v; }
//   int val;
// };
// temp operator+(const temp& a, const temp& b) {
//   temp sum;
//   sum = a.val + b.val;
//   return (sum);
// }

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

using namespace aequatio;

int main(int argc, char const* argv[]) {
  pessum::SetLogHandle(Handle);
  Complex a(3.14,5);
  std::cout << a.String();
  pessum::SaveLog("out.log");
  return 0;
}
