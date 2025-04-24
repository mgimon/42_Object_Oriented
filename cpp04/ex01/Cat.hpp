#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:

		Brain	*brain;

	public:

		Cat();
		Cat(Cat& ref);
		Cat& operator = (Cat& ref);
		~Cat();
		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif
