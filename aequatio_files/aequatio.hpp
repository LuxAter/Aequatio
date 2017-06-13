#ifndef AEQUATIO_CORE_HPP
#define AEQUATIO_CORE_HPP

#define AEQUATIO_VERSION_MAJOR 0
#define AEQUATIO_VERSION_MINOR 0
#define AEQUATIO_VERSION_PATCH 1

namespace aequatio{
  void InitAequatio();
  void TermAequatio();
  void Version(int& major, int& minor, int& patch);
}
#endif
