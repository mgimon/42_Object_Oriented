#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB() {
	//std::cout << name << " has been destroyed." << std::endl;
}

std::string HumanB::getName() const {
	return this->name;
}

void		HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() {
	std::cout << this->name << " attacked with " << this->weapon->getType() << std::endl;
}
