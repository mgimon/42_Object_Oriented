#include "Dog.hpp"

Dog::Dog() : Animal(0) {
	this->isPure = false;
	std::cout << "One Dog was created" << std::endl;
}

Dog::~Dog() {
	std::cout << "One Dog was destroyed" << std::endl;
}

void	Dog::makeSound() {
	std::cout << "Dog says: woof" << std::endl;
}
