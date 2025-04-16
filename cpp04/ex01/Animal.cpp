#include "Animal.hpp"

Animal::Animal() {
	if (this->type != "Dog" && this->type != "Cat")
		std::cout << "One Animal was created" << std::endl;
}

Animal::Animal(std::string type) {
	this->type = type;
	if (this->type != "Dog" && this->type != "Cat")
		std::cout << "One Animal was created" << std::endl;
}

Animal::Animal(Animal& ref) {
	this->type = ref.type;
}

Animal& Animal::operator = (Animal& ref) {
	if (this != &ref) {
		this->type = ref.type;
	}
	return *this;
}

Animal::~Animal() {
	if (this->type != "Dog" && this->type != "Cat")
		std::cout << "One Animal was destroyed" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal says: grrr" << std::endl;
}

void	Animal::setType(std::string const type) {
	this->type = type;
}

std::string Animal::getType() const {
	return this->type;
}
