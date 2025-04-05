#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// All other is inherited from ClapTrap
// (including Canonicals)
class ScavTrap : public ClapTrap {

	public:

		ScavTrap(std::string name);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();

};

#endif
