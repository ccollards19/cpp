#include "Zombie.hpp"

Zombie::Zombie()
	: name("unnamed")
{

}

Zombie::Zombie(std::string new_name)
	: name(new_name)
{

}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name )
{
	Zombie *zom;
	zom = new Zombie(name);
	return (zom);
}

void randomChump( std::string name )
{
	Zombie chump(name);
	chump.announce();
}
