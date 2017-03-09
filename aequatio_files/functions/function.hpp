#ifndef AEQUATIO_FUNCTION_FUNCTION_HPP
#define AEQUATIO_FUNCTION_FUNCTION_HPP
namespace aequatio {

template <class _result, class _arg> struct unary_function {
  typedef _arg argument_type;
  typedef _result result_type;
  unary_function() {}
  unary_function(_result (*def_method)(_arg)) { method = def_method; }
  unary_function(const unary_function &copy_function) {
    method = copy_function.method;
  }
  ~unary_function() { method = nullptr; }
  void operator=(_result (*def_method)(_arg)) { method = def_method; }
  _result (*method)(_arg) = nullptr;
  _result operator()(_arg arg) {
    if (method != nullptr) {
      return (method(arg));
    } else {
      return (_result());
    }
  }
};

template <class _result, class _arg1, class _arg2> struct binary_function {
  typedef _arg1 first_argument_type;
  typedef _arg2 second_argument_type;
  typedef _result result_type;
  binary_function() {}
  binary_function(_result (*def_method)(_arg1, _arg2)) { method = def_method; }
  binary_function(const binary_function &copy_function) {
    method = copy_function.method;
  }
  ~binary_function() { method = nullptr; }
  _result (*method)(_arg1, _arg2) = nullptr;
  _result operator()(_arg1 arg1, _arg2 arg2) {
    if (method != nullptr) {
      return (method(arg1, arg2));
    } else {
      return (_result());
    }
  }
};
}
#endif
