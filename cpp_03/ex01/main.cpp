#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap a;
	ClapTrap kevin("Kevin");
	ScavTrap serena("Serena");

	kevin.ClapTrap::attack("a");
	a.ClapTrap::takeDamage(0);
	a.ClapTrap::beRepaired(0);

	serena.ScavTrap::attack("a");
	serena.ScavTrap::takeDamage(0);
	serena.ScavTrap::beRepaired(0);
	
	return 0;
}
