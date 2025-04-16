#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;
	const WrongAnimal* wa = new WrongCat();
	wa->makeSound();
	const WrongCat* wc = new WrongCat();
	wc->makeSound();
	std::cout << std::endl;
	std::cout  << "----------------" << std::endl;
	std::cout << std::endl;

	delete(j);
	delete(i);
	delete(wa);
	delete(wc);
	delete(meta);

	return (0);
}
