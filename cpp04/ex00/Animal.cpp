#include "Animal.hpp"

Animal::Animal() {
	this->isPure = true;
	std::cout << "One Animal was created" << std::endl;
}

Animal::Animal(int silent) {
	this->isPure = true;
	(void)silent;
}

Animal::Animal(std::string type) {
	this->isPure = true;
	this->type = type;
	std::cout << "One Animal was created" << std::endl;
}

Animal::~Animal() {
	if (this->isPure)
		std::cout << "One Animal was destroyed" << std::endl;
}

void	Animal::makeSound() {
	std::cout << "Animal says: grr" << std::endl;
}

void	Animal::setType(std::string const type) {
	this->type = type;
}

std::string Animal::getType() const {
	return this->type;
}
