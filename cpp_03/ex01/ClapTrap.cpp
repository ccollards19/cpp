#include "ClapTrap.hpp"
#include "iostream"

ClapTrap::ClapTrap ()
	: name("unnamed"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout<<"clap constructor called"<<std::endl;
}

ClapTrap::ClapTrap (std::string name)
	: hit_points(10), energy_points(10), attack_damage(0)
{
	this->name = name;
	std::cout<<"clap constructor called"<<std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &old)
{
	this->name = old.name;
	this->hit_points = old.hit_points;
	this->energy_points = old.energy_points;
	this->attack_damage = old.attack_damage;
	std::cout<<"clap constructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator= (ClapTrap const &old)
{
	if (this != &old)
	{
		this->name = old.name;
		this->hit_points = old.hit_points;
		this->energy_points = old.energy_points;
		this->attack_damage = old.attack_damage;
	}
	return *this;
}
///////////////////////////////////////////////////////////

ClapTrap::~ClapTrap ()
{
	std::cout<<"clap destructor called"<<std::endl;
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

