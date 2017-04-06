#include "aequatio.hpp"
#include <string>
#include <iostream>

void aequatio::Log(std::string format, ...){
  va_list args, buff_args;
  va_start(args, format);
  va_start(buff_args, format);
  ssize_t buff_size = vsnprintf(NULL, 0, format.c_str(), buff_args);
  char* formated_string = new char[buff_size];
  vsprintf(formated_string, format.c_str(), args);
  std::cout << formated_string << "\n";
}
