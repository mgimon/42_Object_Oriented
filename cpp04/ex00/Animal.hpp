#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <fstream>
#include <string>

class Animal {

	protected:

		std::string	type;

	public:

		Animal();
		Animal(std::string type);
		Animal(Animal& ref);
		Animal& operator = (Animal& ref);
		virtual ~Animal();

		virtual void	makeSound() const;
		void	setType(std::string const type);
		std::string getType() const;

};

#endif
