#ifndef SPAN_HPP
#define SPAN_HPP

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
class Span {

    private:

        unsigned int    _N;
        T               container;

    public:

        Span();
        Span(unsigned int N);
        Span(const Span &ref);
        Span& operator = (const Span &ref);
        ~Span();

        void    addNumber(int number);
        int     longestSpan();
        int     shortestSpan();

        T& getContainer() const;
};

template <typename T>
void printContainer(T &container) {

    typename T::iterator it;

    std::cout << std::endl;
    std::cout << GRAY << "Your container has these numbers:" << RESET << std::endl;
    it = container.begin();
    while (it != container.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
}

#endif