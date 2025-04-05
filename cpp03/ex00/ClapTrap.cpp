#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap& ref) {
	this->_name = ref.getName();
	this->_hit_points = ref.getHitPoints();
	this->_energy_points = ref.getEnergyPoints();
	this->_attack_damage = ref.getAttackDamage();
}

ClapTrap& ClapTrap::operator = (ClapTrap& ref) {
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_hit_points = ref._hit_points;
		this->_energy_points = ref._energy_points;
		this->_attack_damage = ref._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	//std::cout << "ClapTrap destructor called" << std::endl;
}

/*--------------------------GETTERS & SETTERS-----------------------------*/

std::string	ClapTrap::getName() const {
	return (this->_name);
}

int			ClapTrap::getHitPoints() const {
	return (this->_hit_points);
}

int			ClapTrap::getEnergyPoints() const {
	return (this->_energy_points);
}

int			ClapTrap::getAttackDamage() const {
	return (this->_attack_damage);
}

void		ClapTrap::setHitPoints(int const hit_points) {
	this->_hit_points = hit_points;
	if (this->_hit_points < 0)
		this->_hit_points = 0;
}

void		ClapTrap::setEnergyPoints(int const energy_points) {
	this->_energy_points = energy_points;
	if (this->_energy_points < 0)
		this->_energy_points = 0;
}

void		ClapTrap::setAttackDamage(int const attack_damage) {
	this->_attack_damage = attack_damage;
}

/*--------------------------MEMBER FUNCTIONS-----------------------------*/

void		ClapTrap::attack(const std::string& target) {
	if (!this->getHitPoints())
		std::cout << this->getName() << " can't attack: he's dead" << std::endl;
	if (!this->getEnergyPoints())
		std::cout << this->getName() << " can't attack: he's got no energy" << std::endl;
	if (this->getHitPoints() && this->getEnergyPoints())
	{
		std::cout << this->getName() << " attacked " << target << "!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void		ClapTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoints() <= 0) {
		std::cout	<< GRAY
					<< this->getName() << " can't take damage anymore. His body, a cold, decaying shell, lies motionless in the vastness of the earth. The winds carry dust and leaves that dance around him, as if mourning the loss of an old companion. " 
					<< this->getName() << ", once full of energy and life, is now just a piece of metal and circuits, frozen in time, with no purpose left but to witness the stillness of the nature that surrounds him."
					<< RESET
					<< std::endl;
        return;
    }
    this->setHitPoints(this->getHitPoints() - amount);
    std::cout << RED << this->getName() << ": " << amount << " points of damage taken" << RESET << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << GRAY << this->getName() << " repaired " << amount << " points of health" << RESET << std::endl;
}

