#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	
}

HumanB::~HumanB() {
	//std::cout << name << " has been destroyed." << std::endl;
}

std::string HumanB::getName() const {
	return this->name;
}
