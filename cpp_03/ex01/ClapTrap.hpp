#pragma once
#include <iostream>

class ClapTrap
{
	protected :
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public	:

		ClapTrap ();
		ClapTrap (ClapTrap const &ClapTrap);
		ClapTrap (std::string name);
		virtual ~ClapTrap ();

		ClapTrap & operator = (ClapTrap const &old_obj);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};
