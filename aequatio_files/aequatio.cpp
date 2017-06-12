#include "aequatio.hpp"
#include <pessum.h>

void aequatio::InitAequatio(){
  pessum::Log(pessum::INFO, "Aequatio Version: %i.%i.%i", "aequatio::InitAequatio", AEQUATIO_VERSION_MAJOR, AEQUATIO_VERSION_MINOR, AEQUATIO_VERSION_PATCH);
}

void aequatio::TermAequatio(){

}

void aequatio::Version(int& major, int& minor, int& patch){
  major = AEQUATIO_VERSION_MAJOR;
  minor = AEQUATIO_VERSION_MINOR;
  patch = AEQUATIO_VERSION_PATCH;
}
