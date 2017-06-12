#include <pessum.h>
#include "aequatio.h"
int main(int argc, const char* argv[]){
  aequatio::InitAequatio();
  aequatio::TermAequatio();
  pessum::SaveLog("out.log");
  return(0);
}
