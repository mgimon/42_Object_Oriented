#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

const std::string&	Weapon::getType() const {

	const std::string& nothing = "nothing";

	if (type.empty())
		return nothing;
	else
		return this->type;
}

void	Weapon::setType(const std::string& newType) {
	this->type = newType;
}
