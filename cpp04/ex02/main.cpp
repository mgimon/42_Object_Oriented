#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	/*
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
	*/

	int	size = 10;
	// these are not Animal objects, this is a pointer to an array allocation
	Animal **animals = new Animal*[size];

	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;
	

	for (int i = 0; i < size; i++) {
		if (i < (size / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++) {
			delete(animals[i]);
	}

	delete[] animals;

	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;

	// this wouldn't compile
	/*Animal *pureAnimal = new Animal();

	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;*/

	return (0);
}
