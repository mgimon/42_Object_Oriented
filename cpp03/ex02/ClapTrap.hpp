#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <fstream>
#include <string>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[97m"

class ClapTrap {

	protected:
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
		bool		_isPure;

	public:

		ClapTrap(std::string name);
		ClapTrap(ClapTrap& ref);
		ClapTrap& operator = (ClapTrap& ref);
		~ClapTrap();

		ClapTrap(std::string name, std::string silent);

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
