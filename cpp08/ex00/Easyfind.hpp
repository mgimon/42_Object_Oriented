#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int n);

#include "Easyfind.tpp"

#endif