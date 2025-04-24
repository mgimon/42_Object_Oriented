#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "One WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	this->type = type;
	std::cout << "One WrongAnimal was created" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "One WrongAnimal was destroyed" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal says: buenas tardes" << std::endl;
}

void	WrongAnimal::setType(std::string const type) {
	this->type = type;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
