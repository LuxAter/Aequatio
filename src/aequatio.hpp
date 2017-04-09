#ifndef AEQUATIO_HPP
#define AEQUATIO_HPP
#include <string>
#include <vector>
namespace aequatio {
  extern std::vector<std::pair<int, std::string>> global_logs;
  extern void (*full_log_handle)(std::pair<int, std::string>);
  extern void (*log_handle)(std::string);
  enum LOG_TYPE { L_NONE, L_ERROR, L_WARNING, L_TRACE };
  void Log(int type = L_TRACE, std::string msg = "", std::string func = "",
           ...);
  std::string GetLog(int type = L_NONE);
  void SaveLog(std::string file = "aequatio.log");
  void SetLogHandle(void (*handle)(std::string));
  void SetLogHandle(void (*handle)(std::pair<int, std::string>));
}
#endif
