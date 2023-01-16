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

void Zombie::set_name(std::string new_name)
{
	name = new_name;
}

void Zombie::announce()
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

