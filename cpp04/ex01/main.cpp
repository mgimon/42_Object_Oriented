#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{

	/*const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;*/


	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;

	int	size = 50;
	const Animal **animals = new const Animal*[size];
	

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

	return (0);
}
