#include "aequatio.hpp"
#include <string>
#include <vector>

namespace aequatio {
std::vector<std::string> loaded_functions;
std::map<std::string, unary_function<double, double>> unary;
std::map<std::string, binary_function<double, double, double>> binary;
}

int aequatio::FindFunction(std::string str) {
  for (int i = 0; i < loaded_functions.size(); i++) {
    if (loaded_functions[i] == str) {
      return (i);
    }
  }
  return (-1);
}

std::string aequatio::ListAvalibleFunctions(int cols) {
  int length = 0, col_count = 0;
  for (int i = 0; i < loaded_functions.size(); i++) {
    if (loaded_functions[i].size() > length) {
      length = loaded_functions[i].size();
    }
  }
  length += 3;
  std::string function_list = "";
  for (int i = 0; i < loaded_functions.size(); i++) {
    if (col_count >= cols && cols != -1 && function_list.size() != 0) {
      function_list += "\n";
      col_count = 0;
    }
    function_list += loaded_functions[i] +
                     std::string(length - loaded_functions[i].size(), ' ');
    col_count++;
  }
  return (function_list);
}
