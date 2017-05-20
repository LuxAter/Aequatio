#ifndef AEQUATIO_OBJECT_OBJECT_PTR_HPP
#define AEQUATIO_OBJECT_OBJECT_PTR_HPP
#include <memory>
#include "number/number_headers.hpp"
#include "object.hpp"
namespace aequatio {
  typedef std::shared_ptr<aequatio::ObjectBase> Object;
  std::shared_ptr<aequatio::ObjectBase> make_object(aequatio::Number num);
  std::shared_ptr<aequatio::ObjectBase> make_object(aequatio::ObjectBase obj);
}

template<>
std::shared_ptr<aequatio::ObjectBase> std::shared_ptr<aequatio::ObjectBase>::operator=(const double& in_value);

#endif
