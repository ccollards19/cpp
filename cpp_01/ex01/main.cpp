#include "Zombie.hpp"

int main()
{
	int i = 0;
	Zombie *horde = zombieHorde(5, "kevin");
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}
