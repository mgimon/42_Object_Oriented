#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "One Cat was created" << std::endl;
}

Cat::~Cat() {
	std::cout << "One Cat was destroyed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Cat says: meow" << std::endl;
}
