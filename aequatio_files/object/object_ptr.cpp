#include <pessum.h>
#include <memory>
#include "number/number_headers.hpp"
#include "object.hpp"
#include "object_ptr.hpp"

std::shared_ptr<aequatio::ObjectBase> aequatio::make_object(
    aequatio::Number num) {
  return (std::make_shared<aequatio::Number>(num));
}
std::shared_ptr<aequatio::ObjectBase> aequatio::make_object(
    aequatio::ObjectBase obj) {
  return (std::make_shared<aequatio::ObjectBase>(obj));
}
