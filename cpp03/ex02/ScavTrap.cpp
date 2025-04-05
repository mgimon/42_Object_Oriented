
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, "silent") {

	this->_isPure = false;
	this->_name = name;
	this->_attack_damage = 20;
	this->_energy_points = 50;
	this->_hit_points = 100;
	std::cout << "ScavTrap " << this->_name << " was created" << std::endl;

}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " was destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->getHitPoints())
		std::cout << this->getName() << " can't attack: he's dead" << std::endl;
	if (!this->getEnergyPoints())
		std::cout << this->getName() << " can't attack: he's got no energy" << std::endl;
	if (this->getHitPoints() && this->getEnergyPoints())
	{
		std::cout << this->getName() << " attacked " << target << " with unstoppable force!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void ScavTrap::guardGate() {
	std::cout << MAGENTA << this->getName() << " is now in Gatekeeper mode " << RESET << std::endl;
}
