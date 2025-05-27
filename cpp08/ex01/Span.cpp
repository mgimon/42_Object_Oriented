
#include "Span.hpp"

template <typename T>
Span<T>::Span() : _N(2), container() {
    std::cout << "Creating a Span object..." << std::endl;
}

template <typename T>
Span<T>::Span(unsigned int N) : _N(N), container() {
    std::cout << "Creating a Span object..." << std::endl;
}

template <typename T>
Span<T>::Span(const Span<T> &ref) : _N(ref._N), container(ref.container) {
    std::cout << "Copying a Span object..." << std::endl;
}

template <typename T>
Span<T>& Span<T>::operator = (const Span<T> &ref) {
    if (this != &ref)
    {
        _N = ref._N;
        container = ref.container;
    }
    std::cout << "Assigning a Span object..." << std::endl;
    return (*this);
}

template <typename T>
Span<T>::~Span() {
    std::cout << "Destroying a Span object..." << std::endl;
}

template <typename T>
void    Span<T>::addNumber(int number) {
    if (this->container.size() >= _N)
        throw (std::exception());
    this->container.push_back(number);
}

template <typename T>
int     Span<T>::longestSpan() {

    T   tmp = this->container;

    if (this->container.size() <= 1)
        throw (std::exception());
    std::sort(tmp.begin(), tmp.end());
    return ((*tmp.end() - 1) - *tmp.begin());
}

template <typename T>
int     Span<T>::shortestSpan() {

    T   tmp = this->container;
    int shortSpan = std::numeric_limits<int>::max();

    if (this->container.size() <= 1)
        throw (std::exception());

    std::sort(tmp.begin(), tmp.end());

    for (size_t i = 1; i < tmp.size(); i++) {
        shortSpan = std::min(shortSpan, (tmp[i] - tmp[i - 1]));
    }
    return (shortSpan);
}

template <typename T>
T& Span<T>::getContainer() const {
    return (this->container);
}

