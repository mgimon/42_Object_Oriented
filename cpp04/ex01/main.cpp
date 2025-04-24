#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


void	separators()
{
	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;
}

void	createAnimals(const Animal **animals, int size)
{
	separators();

	for (int i = 0; i < size; i++) {
		if (i < (size / 2)) {
			animals[i] = new Dog();
			((Dog*)animals[i])->getBrain()->setIdeaInIdeas(0, "I'm a dog");
		}
		else
		{
			animals[i] = new Cat();
			((Cat*)animals[i])->getBrain()->setIdeaInIdeas(0, "I'm a cat");
		}
	}
	separators();
}

void	printAnimals(const Animal **animals, int size)
{
	for (int i = 0; i < size; i++) {
		if (i < (size / 2)) {
			std::cout << "Animal " << i << ": " ;
			((Dog*)animals[i])->getBrain()->printIdeas();
		}
		else {
			std::cout << "Animal " << i << ": " ;
			((Cat*)animals[i])->getBrain()->printIdeas();
		}
	}
}

void	deleteAnimals(const Animal **animals, int size)
{
	separators();

	for (int i = 0; i < size; i++) {
			delete(animals[i]);
	}

	delete[] animals;
	separators();
}

int	main(void)
{
	/*
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;*/
	

	int	size = 10;
	const Animal **animals = new const Animal*[size];

	createAnimals(animals, size);
	printAnimals(animals, size);
	deleteAnimals(animals, size);

	return (0);
}
