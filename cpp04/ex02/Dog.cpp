#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "One Dog was created" << std::endl;
}

// we allocate copy the brain too
Dog::Dog(Dog& ref) : Animal(ref) {
	this->brain = new Brain(*ref.brain);
}

// we allocate copy the brain too
Dog& Dog::operator = (Dog& ref) {
    if (this != &ref) {
        Animal::operator=(ref);
        delete this->brain;
        this->brain = new Brain(*ref.brain);
    }
    return *this;
}

Dog::~Dog() {
	delete(brain);
	std::cout << "One Dog was destroyed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog says: woof" << std::endl;
}

Brain* Dog::getBrain() const {
    return (brain);
}
