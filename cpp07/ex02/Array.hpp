#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

// Class Array contains an array of template nodes:
template <typename T>
class Array {
    private:
        T               *elements;
        unsigned int    _size;

    public:

        // ** CANONICAL ** //

        Array() : elements(NULL), _size(0) {
            std::cout << GRAY << "Creating a new Array..." << RESET << std::endl;
        };

        Array(unsigned int n) : elements(new T[n]()), _size(n) {
            std::cout << GRAY << "Creating a new Array..." << RESET << std::endl;
        };

        Array(const Array &ref) : elements(new T[ref._size]), _size(ref._size) {
            for (unsigned int i = 0; i < ref._size; i++)
                this->elements[i] = ref.elements[i];
            std::cout << GRAY << "Copying a new Array..." << RESET << std::endl;
        };

        Array& operator = (const Array &ref) {
            if (this != &ref)
            {
                delete[] this->elements;

                this->elements = new T[ref._size];
                for (unsigned int i = 0; i < ref._size; i++)
                    this->elements[i] = ref.elements[i];

                this->_size = ref._size;
            }
            std::cout << GRAY << "Assigning a new Array..." << RESET << std::endl;
            return (*this);
        };

        ~Array() {
            delete[] this->elements;
            std::cout << GRAY << "Destroying an Array..." << RESET << std::endl;
        };

        // ** OVERLOAD OF [] IN NODES ** //
        // Used to print or otherwise access the template nodes with []
        T& operator [] (unsigned int n) {
            if (n >= this->_size)
                throw (std::exception());
            return (this->elements[n]);
        };

        // ** MEMBER FUNCTIONS ** //
        unsigned int size() const {
            return this->_size;
        };
};

#endif