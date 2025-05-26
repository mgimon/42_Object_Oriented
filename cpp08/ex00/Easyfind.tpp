#ifndef EASYFIND_TPP
#define EASYFIND_TPP

// typename -> tipo dependiente
// typename T::iterator -> iterador del tipo dependiente
template <typename T>
typename T::iterator easyfind(T &object, int n) {
    
    typename T::iterator it;

    it = std::find(object.begin(), object.end(), n);

    if (it != object.end())
        return (it);
    else
        return (object.end());
}

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