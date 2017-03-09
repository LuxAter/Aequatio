#ifndef AEQUATIO_AEQUATIO_HPP
#define AEQUATIO_AEQUATIO_HPP
#include "functions/function.hpp"
#include <map>
#include <string>
#include <vector>
namespace aequatio {
extern std::vector<std::string> loaded_functions;
extern std::map<std::string, unary_function<double, double>> unary;
extern std::map<std::string, binary_function<double, double, double>> binary;
int FindFunction(std::string str);
std::string ListAvalibleFunctions(int cols = -1);
}
#endif
