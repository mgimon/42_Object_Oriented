#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"


Base* generate() {

	std::srand(std::time(NULL));
	int n = std::rand() % 3;

	if (n == 0)
		return (new A);
	else if (n == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "Object type: " << GREEN << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object type: " << GREEN << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object type: " << GREEN << "C" << RESET << std::endl;
}

void identify(Base& p) {

	try {
		dynamic_cast<A&>(p);
		std::cout << "Object type: " << GREEN << "A" << RESET << std::endl;
		return ;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		dynamic_cast<B&>(p);
		std::cout << "Object type: " << GREEN << "B" << RESET << std::endl;
		return ;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		dynamic_cast<C&>(p);
		std::cout << "Object type: " << GREEN << "C" << RESET << std::endl;
		return ;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void) {

	Base *object = generate();

	identify(object);
	identify(*object);

	return (0);
}
