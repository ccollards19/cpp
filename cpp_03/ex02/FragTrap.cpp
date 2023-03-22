#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap ()
{
	std::cout<<"Frag trap constructor"<<std::endl;
	this->name = "unnamed";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap (std::string name)
{
	std::cout<<"Frag trap constructor"<<std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap (FragTrap const &old)
{
	std::cout<<"Frag trap constructor"<<std::endl;
	this->name = old.name;
	this->hit_points = old.hit_points;
	this->energy_points = old.energy_points;
	this->attack_damage = old.attack_damage;
}

FragTrap &FragTrap::operator= (FragTrap const &old)
{
	if (&old != this)
	{
		std::cout<<"Frag trap constructor"<<std::endl;
		this->name = old.name;
		this->hit_points = old.hit_points;
		this->energy_points = old.energy_points;
		this->attack_damage = old.attack_damage;
	}
	return *this;
}
///////////////////////////////////////////////////////////

void FragTrap::attack(const std::string& target)
{
	std::cout<<"FragTrap "<<this->name<<" attacks "<<target
	<<", causing "<< this->attack_damage << " points of damage!"<<std::endl;
}

FragTrap::~FragTrap ()
{
	std::cout<<"Frag trap destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

void FragTrap::highFivesGuys()
{
	std::cout<<this->name<<" : \"High Fives Guys\""<<std::endl;
}

