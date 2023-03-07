#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

void HumanB::attack()
{
	if (armed)
		std::cout<<name<<" attack with their "<<weapon->getType()<<std::endl;
}

HumanB::HumanB(std::string name)
	: name(name), armed(false)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	armed = true;
}

HumanB::~HumanB()
{

}
