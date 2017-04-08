#include <vector>
#include "../../symbol.hpp"
#include "vector.hpp"

aequatio::Vector::Vector() {}

aequatio::Vector::Vector(std::vector<Symbol*> elements) {}

aequatio::Vector::~Vector() { vec_terms.clear(); }
