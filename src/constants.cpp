#include <map>
#include <string>
#include "constants.hpp"
namespace aequatio {
  std::map<std::string, double> constants;
}

void aequatio::LoadConstants() {
  constants["PI"] = 3.14159265358979323846;
  constants["E"] = 2.71828182845904523536;
  constants["C"] = 299792458;
  constants["H"] = 6.62607004e-34;
  constants["L"] = 6.02214086e23;
}
