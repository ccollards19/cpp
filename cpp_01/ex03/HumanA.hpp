#pragma once
#include "Weapon.hpp"

#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(void);
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack();
};
