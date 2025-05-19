#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t length, void (*Function)(const T &param)) {
	for (size_t i = 0; i < length; i++) {
		Function(array[i]);
	}
}

// function for testing
template <typename T>
void printFunc(T& value) {
    std::cout << value << std::endl;
}

#endif
