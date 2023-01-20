#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
		
	public :
		void guardGate();		
		ScavTrap ();
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const &ScavTrap);

		ScavTrap& operator = (ScavTrap const &old_obj);
		~ScavTrap ();
};
