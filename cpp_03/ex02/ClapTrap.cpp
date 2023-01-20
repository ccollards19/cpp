#include "ClapTrap.hpp"
#include "iostream"
#include "cmath"

ClapTrap::ClapTrap ()
	: name("unnamed"), hit_points(10), energy_points(10), attack_damage(0)
{

}

ClapTrap::ClapTrap (std::string name)
	: hit_points(10), energy_points(10), attack_damage(0)
{
	this->name = name;
}

ClapTrap::ClapTrap (ClapTrap const &old)
{
	this->name = old.name;
	this->name = old.hit_points;
	this->name = old.energy_points;
	this->name = old.attack_damage;
}

ClapTrap &ClapTrap::operator= (ClapTrap const &old)
{
	this->name = old.name;
	this->name = old.hit_points;
	this->name = old.energy_points;
	this->name = old.attack_damage;
	return *this;
}
///////////////////////////////////////////////////////////

ClapTrap::~ClapTrap ()
{
	std::cout<<"clap trap destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

void ClapTrap::attack(const std::string& target)
{
	std::cout<<"ClapTrap "<<this->name<<" attacks "<<target
	<<", causing "<< this->attack_damage << " points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout<<"ClapTrap "<<this->name<<", takes "
	<< amount << " points of damage!"<<std::endl;
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout<<"ClapTrap "<<this->name<<", get healed "
	<< amount << " hit points"<<std::endl;
	this->hit_points += amount;
}

