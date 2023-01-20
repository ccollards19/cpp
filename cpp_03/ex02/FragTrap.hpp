#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private :
		
	public :
		void highFivesGuys();		
		FragTrap ();
		FragTrap (std::string name);
		FragTrap (FragTrap const &FragTrap);

		FragTrap& operator = (FragTrap const &old_obj);
		~FragTrap ();
};
