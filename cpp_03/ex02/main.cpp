#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap a;
	ClapTrap kevin("Kevin");
	ScavTrap serena("Serena");
	ClapTrap *ptr = &serena;
	FragTrap dylan("Dylan");

	kevin.attack("a");
	a.takeDamage(0);
	a.beRepaired(0);

	serena.attack("a");
	serena.takeDamage(0);
	serena.beRepaired(0);
	serena.guardGate();
	
	ptr->attack("a");
	ptr->takeDamage(0);
	ptr->beRepaired(0);

	dylan.attack("a");
	dylan.takeDamage(0);
	dylan.beRepaired(0);
	dylan.highFivesGuys();

	ptr = &dylan;
	ptr->attack("a");
	ptr->takeDamage(0);
	ptr->beRepaired(0);

	ptr = new FragTrap();
	delete ptr;
	return 0;
}
