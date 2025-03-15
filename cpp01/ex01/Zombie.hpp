#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{

private:

    std::string name;

public:

    Zombie() {};
    Zombie(std::string name);
    ~Zombie();

    void announce();
    void setName(std::string name);
    std::string getName() const;
};

Zombie* zombieHorde(int N, std::string name);
void deleteHorde(Zombie* zombieHorde);

#endif
