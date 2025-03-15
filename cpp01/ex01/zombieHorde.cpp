#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

if (N <= 0)
	return (NULL);

Zombie* horde = new Zombie[N];

for (int i = 0; i < N; i++)
{
	horde[i].setName(name);
	horde[i].announce();
}

return (horde);

}

void deleteHorde(Zombie* zombieHorde) {
	if (!zombieHorde)
		return ;
	delete[] zombieHorde;
}
