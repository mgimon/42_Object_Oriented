#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "One Dog was created" << std::endl;
}

Dog::~Dog() {
	std::cout << "One Dog was destroyed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog says: woof" << std::endl;
}
