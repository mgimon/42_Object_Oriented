#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{

private:

	std::string	name;
	Weapon&		weapon;

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	std::string	getName() const;
	void		setWeapon(Weapon weapon);
	void 		attack();

};


#endif
