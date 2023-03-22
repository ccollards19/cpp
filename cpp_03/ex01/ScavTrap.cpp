#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap ()
{
	this->name = "unnamed";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout<<"scav constructor called"<<std::endl;
}

ScavTrap::ScavTrap (std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout<<"scav constructor called"<<std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &old)
{
	this->name = old.name;
	this->hit_points = old.hit_points;
	this->energy_points = old.energy_points;
	this->attack_damage = old.attack_damage;
	std::cout<<"scav constructor called"<<std::endl;
}

ScavTrap &ScavTrap::operator= (ScavTrap const &old)
{
	if (&old != this)
	{
		this->name = old.name;
		this->hit_points = old.hit_points;
		this->energy_points = old.energy_points;
		this->attack_damage = old.attack_damage;
	}
	return *this;
}
///////////////////////////////////////////////////////////

ScavTrap::~ScavTrap ()
{
	std::cout<<"scav destructor called"<<std::endl;

}
///////////////////////////////////////////////////////////

void ScavTrap::attack(const std::string& target)
{
	std::cout<<"ScavTrap "<<this->name<<" attacks "<<target
	<<", causing "<< this->attack_damage << " points of damage!"<<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<<this->name<<" is guarding the gate"<<std::endl;
}

