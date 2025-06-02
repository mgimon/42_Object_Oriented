#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

template <typename T>
class MutantStack : public std::stack<T> {

	private:
	public:

		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack &ref);
		MutantStack& operator = (const MutantStack &ref);
		~MutantStack();

		iterator begin();
		iterator end();

};


#include "MutantStack.tpp"

#endif
