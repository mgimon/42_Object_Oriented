#ifndef BASE_HPP
#define BASE_HPP

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

class Base {
	public:
    	virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
