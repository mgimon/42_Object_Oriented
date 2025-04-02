#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <fstream>
#include <string>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW    "\033[33m"
#define RESET   "\033[0m"

class ClapTrap {

	private:

		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:

		ClapTrap(std::string name);
		ClapTrap(ClapTrap& ref);
		ClapTrap& operator = (ClapTrap& ref);
		~ClapTrap();

		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergyPoints() const;
		int			getAttackDamage() const;
		void		setHitPoints(int const hit_points);
		void		setEnergyPoints(int const energy_points);
		void		setAttackDamage(int const attack_damage);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

};

#endif
