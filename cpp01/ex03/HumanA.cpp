#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {

}

HumanA::~HumanA() {
}

std::string HumanA::getName() const {
	return this->name;
}

void		HumanA::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}

void	HumanA::attack() {
	std::cout << this->name << " attacked with " << this->weapon.getType() << std::endl;
}
