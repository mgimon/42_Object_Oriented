#include "Zombie.hpp"

Zombie::Zombie(std::string name) {

this->name = name;

}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed." << std::endl;
}

std::string Zombie::getName(void) const {

return this->name;

}

void Zombie::setName(std::string name) {

this->name = name;

}

void Zombie::announce(void) {

std::cout << this->getName() << ": ";
std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;

}
