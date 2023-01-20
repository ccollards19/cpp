#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap a;
	ClapTrap kevin("Kevin");
	ScavTrap serena("Serena");
	FragTrap dylan("Dylan");

	kevin.ClapTrap::attack("a");
	a.ClapTrap::takeDamage(0);
	a.ClapTrap::beRepaired(0);

	serena.ScavTrap::attack("a");
	serena.ScavTrap::takeDamage(0);
	serena.ScavTrap::beRepaired(0);
	serena.guardGate();
	
	dylan.ScavTrap::attack("a");
	dylan.ScavTrap::takeDamage(0);
	dylan.ScavTrap::beRepaired(0);
	dylan.highFivesGuys();
	return 0;
}
