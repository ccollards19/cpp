#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap a;
	ClapTrap kevin("Kevin");

	kevin.ClapTrap::attack("a");
	a.ClapTrap::takeDamage(0);
	a.ClapTrap::beRepaired(0);
	
	return 0;
}
