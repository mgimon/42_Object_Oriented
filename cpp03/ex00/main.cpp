#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Clappy");
    ClapTrap clap2("Mr. Claps");

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;

    clap2.beRepaired(3);
    std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
	clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
	std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
	clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
	std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
	std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;

    clap2.attack(clap1.getName());
    clap1.takeDamage(clap2.getAttackDamage());
    std::cout << std::endl;

	std::cout << YELLOW << clap1.getName() << " HP: " << clap1.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << clap1.getName() << " energy points: " << clap1.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << clap2.getName() << " energy points: " << clap2.getEnergyPoints() << RESET << std::endl;

	return (0);
}
