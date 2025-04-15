#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <fstream>
#include <string>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[97m"

class Animal {

	protected:

		std::string	type;

	public:

		Animal();
		Animal(std::string type);
		Animal(Animal& ref);
		Animal& operator = (Animal& ref);
		virtual ~Animal();

		virtual void	makeSound() const = 0;
		void	setType(std::string const type);
		std::string getType() const;

};

#endif
