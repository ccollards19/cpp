#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap ()
{
	this->name = "unnamed";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap (std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap (ScavTrap const &old)
{
	this->name = old.name;
	this->hit_points = old.hit_points;
	this->energy_points = old.energy_points;
	this->attack_damage = old.attack_damage;
}

ScavTrap &ScavTrap::operator= (ScavTrap const &old)
{
	this->name = old.name;
	this->hit_points = old.hit_points;
	this->energy_points = old.energy_points;
	this->attack_damage = old.attack_damage;
	return *this;
}
///////////////////////////////////////////////////////////

ScavTrap::~ScavTrap ()
{

}
///////////////////////////////////////////////////////////

void ScavTrap::guardGate()
{
	std::cout<<this->name<<" is guarding the gate"<<std::endl;
}

