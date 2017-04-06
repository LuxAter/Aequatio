#ifndef AEQUATIO_CONSTANTS_HPP
#define AEQUATIO_CONSTANTS_HPP
#include <map>
#include <string>
namespace aequatio {
  extern std::map<std::string, double> constants;
  void LoadConstants();
}
#endif
