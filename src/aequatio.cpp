#include <fstream>
#include <string>
#include "aequatio.hpp"

namespace aequatio {
  std::vector<std::pair<int, std::string>> global_logs;
  void (*log_handle)(std::string) = NULL;
}

void aequatio::Log(int type, std::string msg, std::string func, ...) {
  std::string str;
  va_list args, buff_args;
  va_start(args, func);
  va_start(buff_args, func);
  ssize_t buff_size = vsnprintf(NULL, 0, str.c_str(), buff_args);
  char* formated_string = new char[buff_size];
  vsprintf(formated_string, msg.c_str(), args);
  va_end(args);
  va_end(buff_args);
  str = std::string(formated_string);
  if (type == L_NONE) {
    str = "[(null)] " + str;
  } else if (type == L_ERROR) {
    str = "[ERROR] " + str;
  } else if (type == L_WARNING) {
    str = "[WARNING] " + str;
  } else if (type == L_TRACE) {
    str = "[TRACE] " + str;
  }
  str = str + " [" + func + "]";
  global_logs.push_back(std::make_pair(type, str));
  if (log_handle != NULL) {
    log_handle(str);
  }
}

std::string aequatio::GetLog(int type) {
  std::string str = "";
  if (type == L_NONE && global_logs.size() > 0) {
    str = global_logs.end()->second;
  }
  for (int i = global_logs.size() - 1; i >= 0 && str == ""; i--) {
    if (global_logs[i].first == type) {
      str = global_logs[i].second;
    }
  }
  return (str);
}

void aequatio::SaveLog(std::string file) {
  std::ofstream output(file.c_str(), std::ios::out);
  if (output.is_open()) {
    for (int i = 0; i < global_logs.size(); i++) {
      output << global_logs[i].second << "\n";
    }
    output.close();
  }
}

void aequatio::SetLogHandle(void (*handle)(std::string)) {
  log_handle = handle;
}
