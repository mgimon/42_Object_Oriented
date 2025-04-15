#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "One Dog was created" << std::endl;
}

Dog::~Dog() {
	delete(brain);
	std::cout << "One Dog was destroyed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog says: woof" << std::endl;
}
