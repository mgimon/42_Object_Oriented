#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "One Cat was created" << std::endl;
}

// we allocate copy the brain too
Cat::Cat(Cat& ref) : Animal(ref) {
	this->brain = new Brain(*ref.brain);
}

// we allocate copy the brain too
Cat& Cat::operator = (Cat& ref) {
    if (this != &ref) {
        Animal::operator=(ref);
        delete this->brain;
        this->brain = new Brain(*ref.brain);
    }
    return *this;
}

Cat::~Cat() {
	delete(brain);
	std::cout << "One Cat was destroyed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Cat says: meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return (brain);
}
