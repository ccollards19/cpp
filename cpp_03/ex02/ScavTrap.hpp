#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
		
	public :
		void guardGate();		
		void attack(const std::string& target);
		ScavTrap ();
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const &ScavTrap);

		ScavTrap& operator = (ScavTrap const &old_obj);
		~ScavTrap ();
};
