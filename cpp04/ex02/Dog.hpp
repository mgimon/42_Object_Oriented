#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:

		Brain	*brain;

	public:

		Dog();
		Dog(Dog& ref);
		Dog& operator = (Dog& ref);
		~Dog();
		void	makeSound() const;
};

#endif
