#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap1("Clappie");
    ScavTrap scav1("Scavvie");

    std::cout << std::endl;

    clap1.attack(scav1.getName());
    scav1.takeDamage(5);
    std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    scav1.beRepaired(3);
    std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

	clap1.attack(scav1.getName());
    scav1.takeDamage(5);
    
	std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

	clap1.attack(scav1.getName());
    scav1.takeDamage(5);
	std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    scav1.guardGate();
    scav1.attack(clap1.getName());
    clap1.takeDamage(20);
    std::cout << YELLOW << clap1.getName() << " HP: " << clap1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

	return (0);
}
