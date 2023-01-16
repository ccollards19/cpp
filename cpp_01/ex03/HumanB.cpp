#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

void HumanB::attack()
{
	std::cout<<name<<" attack with their "<<weapon->getType()<<std::endl;
}

HumanB::HumanB(std::string name)
	: name(name)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::~HumanB()
{

}
