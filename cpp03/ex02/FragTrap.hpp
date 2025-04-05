#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// All other is inherited from ClapTrap
// (including Canonicals)
class FragTrap : public ClapTrap {

	public:

		FragTrap(std::string name);
		~FragTrap();
		void	highFivesGuys();

};

#endif
