#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "One WrongCat was created" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "One WrongCat was destroyed" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongCat says: woof... I mean, meow!" << std::endl;
}
