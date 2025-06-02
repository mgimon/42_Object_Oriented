
#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

// since it has the same attributes, it can inherit std::stack implementation
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &ref) : std::stack<T>(ref) {

}

// it can also inherit but we need to return a MutantStack object
template <typename T>
MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T> &ref) {
	if (this != &ref)
	{
		this->std::stack<T>::operator=(ref);
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

#endif
