#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

template <typename T>
typename T::iterator easyfind(T &container, int n);

template <typename T>
void printContainer(T &container);

#include "Easyfind.tpp"

#endif