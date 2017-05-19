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

int main(int argc, char const* argv[]) {
  pessum::SetLogHandle(Handle);
  aequatio::Number a(3.1415);
  aequatio::Object b = aequatio::make_object(aequatio::Number(3.1415));
  // std::make_shared<aequatio::Number>(aequatio::Number(3.1415));
  // aequatio::make_object(aequatio::Number(3.1415));
  aequatio::ObjectBase* c = new aequatio::Number(3.1415);
  std::cout << a.String() << "\n";
  std::cout << b->String() << "\n";
  std::cout << c->String() << "\n";

  // std::shared_ptr<aequatio::Object> a =
  //     std::make_shared<aequatio::Object>(aequatio::Object());
  // a->value = -1;
  // std::shared_ptr<aequatio::Object> b =
  //     std::make_shared<aequatio::Object>(aequatio::Object());
  // b->value = 20;
  // a = a + b;
  // std::cout << a->value << "\n";
  // Symbol a(1);
  // Symbol b(2);
  // Symbol c(3);
  // Symbol d(0);
  // Symbol veca({a, b, c});
  // Symbol vecb({b, c, a});
  // Symbol vecc({c, a, b});
  // Symbol mata({{a, b, c}, {b, c, a}, {c, a, b}});
  // Symbol matb({{b, c, a}, {c, a, b}, {a, b, c}});
  // Symbol matc({{c, a, b}, {a, b, c}, {b, c, a}});
  // Symbol matd({{a, b, c, d}, {a, b, c, d}, {a, b, c, d}, {a, b, c, d}});
  // std::cout << "a:" << a.String() << "\n";
  // std::cout << "b:" << b.String() << "\n";
  // std::cout << "c:" << c.String() << "\n";
  // std::cout << "d:" << d.String() << "\n";
  // std::cout << "vec a:" << veca.String() << "\n";
  // std::cout << "vec b:" << vecb.String() << "\n";
  // std::cout << "vec c:" << vecc.String() << "\n";
  // std::cout << "mat a:" << mata.String() << "\n";
  // std::cout << "mat b:" << matb.String() << "\n";
  // std::cout << "mat c:" << matc.String() << "\n";
  // std::cout << "mat d:" << matd.String() << "\n";
  // std::cout << "==========================\n";
  // std::cout << Transpose(mata).String() << "\n";
  // std::cout << "det:" << Determinant(mata).String() << "\n";
  // std::cout << "trace:" << Trace(mata).String() << "\n";
  // std::cout << "inverse:" << Inverse(mata).String() << "\n";
  pessum::SaveLog("out.log");
  return 0;
}
