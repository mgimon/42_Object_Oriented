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

		MutantStack();
		MutantStack(const MutantStack &ref);
		MutantStack& operator = (const MutantStack &ref);
		~MutantStack();

};

template <typename T>
void	printStack(T container) {

	T copy = container;

	std::cout << std::endl;
	std::cout << "Your stack contains:" << std::endl;
	std::cout << std::endl;

	while (!copy.empty())
	{
		std::cout << copy.top() << std::endl;
		copy.pop();
	}
	std::cout << std::endl;
}

template <typename T>
void	printList(T container) {

	std::cout << std::endl;
	std::cout << "Your list contains:" << std::endl;
	std::cout << std::endl;

	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

}


#include "MutantStack.tpp"

#endif
