#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, "silent") {

	this->_isPure = false;
	this->_name = name;
	this->_attack_damage = 30;
	this->_energy_points = 100;
	this->_hit_points = 100;
	std::cout << "FragTrap " << this->_name << " was created" << std::endl;

}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " was destroyed" << std::endl;
}

void    FragTrap::highFivesGuys() {

    std::cout << MAGENTA << this->_name << " successfully high-fived everyone!" << RESET << std::endl;

}