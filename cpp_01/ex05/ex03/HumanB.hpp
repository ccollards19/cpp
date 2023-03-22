#pragma once

#include "Weapon.hpp"

#include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
		bool armed;
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void attack();
		void setWeapon(Weapon &weapon);
};
