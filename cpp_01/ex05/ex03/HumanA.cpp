#include "HumanA.hpp"
#include "Weapon.hpp"

#include <iostream>

void HumanA::attack()
{
	std::cout<<name<<" attack with their "<<weapon.getType()<<std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{

}
