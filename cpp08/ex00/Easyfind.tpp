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

#endif