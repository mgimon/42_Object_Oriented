#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <fstream>
#include <string>

class WrongAnimal {

	protected:

		std::string	type;

	public:

		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal& ref);
		WrongAnimal& operator = (WrongAnimal& ref);
		~WrongAnimal();

		void	makeSound() const;
		void	setType(std::string const type);
		std::string getType() const;

};

#endif
