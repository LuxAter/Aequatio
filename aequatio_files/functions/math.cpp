#include "../aequatio.hpp"
#include "math.hpp"
#include <cmath>
#include <vector>

void aequatio::LoadMathFunctions() {
  std::vector<std::string> math_func = {
      "cos",       "sin",      "tan",       "acos",   "asin",   "atan",
      "atan2",     "cosh",     "sinh",      "tanh",   "acosh",  "asinh",
      "atanh",     "exp",      "ln",        "log",    "exp2",   "expm1",
      "lnp1",      "log2",     "logb",      "pow",    "aqrt",   "cbrt",
      "hypot",     "erf",      "erfc",      "tgamma", "lgamma", "ceil",
      "floor",     "fmod",     "trunc",     "round",  "rint",   "nearbyint",
      "remainder", "copysign", "nextafter", "fdim",   "fmax",   "fmin",
      "abs"};
  // Trigonometric
  unary["cos"] = cos;
  unary["sin"] = sin;
  unary["tan"] = tan;
  unary["acos"] = acos;
  unary["asin"] = asin;
  unary["atan"] = atan;
  binary["atan2"] = atan2;
  // Hyperbolic
  unary["cosh"] = cosh;
  unary["sinh"] = sinh;
  unary["tanh"] = tanh;
  unary["acosh"] = acosh;
  unary["asinh"] = asinh;
  unary["atanh"] = atanh;
  // Exponential and Logarithmic
  unary["exp"] = exp;
  unary["ln"] = log;
  unary["log"] = log10;
  unary["exp2"] = exp2;
  unary["expm1"] = expm1;
  unary["lnp1"] = log1p;
  unary["log2"] = log2;
  unary["logb"] = logb;
  // Power
  binary["pow"] = pow;
  unary["sqrt"] = sqrt;
  unary["cbrt"] = cbrt;
  binary["hypot"] = hypot;
  // Error and Gamma
  unary["erf"] = erf;
  unary["erfc"] = erfc;
  unary["tgamma"] = tgamma;
  unary["lgamma"] = lgamma;
  // Rounding and Remainder
  unary["ceil"] = ceil;
  unary["floor"] = floor;
  binary["fmod"] = fmod;
  unary["trunc"] = trunc;
  unary["round"] = round;
  unary["rint"] = rint;
  unary["nearbyint"] = nearbyint;
  binary["remainder"] = remainder;
  // Floating-Point Manipulation
  binary["copysign"] = copysign;
  binary["nextafter"] = nextafter;
  // Min Max Diff
  binary["fdim"] = fdim;
  binary["fmax"] = fmax;
  binary["fmin"] = fmin;
  // Other
  unary["abs"] = fabs;

  loaded_functions.insert(loaded_functions.end(), math_func.begin(),
                          math_func.end());
}
