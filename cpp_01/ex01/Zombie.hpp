#pragma once
#include <iostream>

class Zombie
{
	std::string name;

	public :
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void set_name(std::string new_name);
		void announce(void);
};

Zombie *zombieHorde(int N, std::string name);
