
#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	//std::cout << "Creating a MutantStack..." << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &ref) : std::stack<T>(ref) {
	//std::cout << "Copying a MutantStack..." << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T> &ref) {
	if (this != &ref)
	{
		std::stack<T>::operator=(ref);
	}
	//std::cout << "Assigning a MutantStack..." << std::endl;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {
	//std::cout << "Destroying a MutantStack..." << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

#endif
