#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private :
		
	public :
		void highFivesGuys();		
		void attack(const std::string& target);
		FragTrap ();
		FragTrap (std::string name);
		FragTrap (FragTrap const &FragTrap);

		FragTrap& operator = (FragTrap const &old_obj);
		~FragTrap ();
};
