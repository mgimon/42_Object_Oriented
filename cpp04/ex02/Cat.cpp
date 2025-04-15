#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "One Cat was created" << std::endl;
}

Cat::~Cat() {
	delete(brain);
	std::cout << "One Cat was destroyed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Cat says: meow" << std::endl;
}
