#include "Zombie.hpp"

int main()
{
	Zombie a;
	Zombie b("kevin");

	b.announce();
	a.announce();
	randomChump("chum");
	Zombie *zom = newZombie("zom");
	zom->announce();
	delete zom;
}
