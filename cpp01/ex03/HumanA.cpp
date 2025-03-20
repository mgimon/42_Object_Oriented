#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {

	this->weapon = weapon;
	
}

HumanA::~HumanA() {
	//std::cout << name << " has been destroyed." << std::endl;
}

std::string HumanA::getName() const {
	return this->name;
}
