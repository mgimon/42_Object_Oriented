#include "Zombie.hpp"

int main(void)
{
    Zombie* z;
    
    std::cout << std::endl;

    std::cout << "*** Creating a new zombie on the heap ***" << std::endl;
    z = newZombie("Johnny");
    z->announce();
    delete z;

    std::cout << std::endl;

    std::cout << "*** Creating a new zombie on the stack ***" << std::endl;
    randomChump("Temporary Zombie");

    std::cout << std::endl;
    return (0);
}