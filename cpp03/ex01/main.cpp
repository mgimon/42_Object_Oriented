#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap1("Clappy");
    ScavTrap scav1("Scavvy");

    std::cout << std::endl;

    clap1.attack(scav1.getName());
    scav1.takeDamage(clap1.getAttackDamage());
    std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    scav1.beRepaired(3);
    std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

	clap1.attack(scav1.getName());
    scav1.takeDamage(clap1.getAttackDamage());
    
	std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

	clap1.attack(scav1.getName());
    scav1.takeDamage(clap1.getAttackDamage());
	std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    scav1.guardGate();
    std::cout << std::endl;
    scav1.attack(clap1.getName());
    clap1.takeDamage(scav1.getAttackDamage());
    std::cout << YELLOW << clap1.getName() << " HP: " << clap1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    scav1.attack(clap1.getName());
    clap1.takeDamage(scav1.getAttackDamage());
    std::cout << YELLOW << clap1.getName() << " HP: " << clap1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << clap1.getName() << " HP: " << clap1.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << clap1.getName() << " energy points: " << clap1.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << scav1.getName() << " energy points: " << scav1.getEnergyPoints() << RESET << std::endl;

	return (0);
}
