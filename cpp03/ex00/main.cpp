#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Johnny");
    ClapTrap clap2("Bobbert");

    clap1.attack(clap2.getName());
    clap2.takeDamage(5);
    std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;

    clap2.beRepaired(3);
    std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
	clap1.attack(clap2.getName());
    clap2.takeDamage(5);
	std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
	clap1.attack(clap2.getName());
    clap2.takeDamage(5);
	std::cout << YELLOW << clap2.getName() << " HP: " << clap2.getHitPoints() << RESET << std::endl;
	return (0);
}
