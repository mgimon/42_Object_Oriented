#include "Zombie.hpp"

int main(void)
{
    int N = 6;
    Zombie* horde = zombieHorde(N, "Johnny");
    deleteHorde(horde);
    return (0);
}
