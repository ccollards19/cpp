#pragma once
#include <iostream>

class ClapTrap
{
	private :
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public	:
		ClapTrap ();
		ClapTrap (ClapTrap const &ClapTrap);
		ClapTrap (std::string name);
		~ClapTrap ();

		ClapTrap & operator = (ClapTrap const &old_obj);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

std::ostream & operator<< (std::ostream &out, const ClapTrap &obj);
