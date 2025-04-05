#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap clap1("Clappy");
    ScavTrap scav1("Scavvy");
    FragTrap frag1("Fraggy");

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

    scav1.attack(frag1.getName());
    frag1.takeDamage(scav1.getAttackDamage());
    std::cout << YELLOW << frag1.getName() << " HP: " << frag1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    scav1.attack(frag1.getName());
    frag1.takeDamage(scav1.getAttackDamage());
    std::cout << YELLOW << frag1.getName() << " HP: " << frag1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    frag1.beRepaired(40);
    std::cout << YELLOW << frag1.getName() << " HP: " << frag1.getHitPoints() << RESET << std::endl;
    std::cout << std::endl;

    frag1.highFivesGuys();
    frag1.attack(clap1.getName());
    clap1.takeDamage(frag1.getAttackDamage());
    frag1.attack(clap1.getName());
    clap1.takeDamage(frag1.getAttackDamage());
    std::cout << std::endl;

    std::cout << YELLOW << clap1.getName() << " HP: " << clap1.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << scav1.getName() << " HP: " << scav1.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << frag1.getName() << " HP: " << frag1.getHitPoints() << RESET << std::endl;
    std::cout << YELLOW << clap1.getName() << " energy points: " << clap1.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << scav1.getName() << " energy points: " << scav1.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << frag1.getName() << " energy points: " << frag1.getEnergyPoints() << RESET << std::endl;

    return 0;
}
