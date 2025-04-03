
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
	std::cout << this->getName() << " attacked " << target << " with unstoppable force!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in Gatekeeper mode " << std::endl;
}
