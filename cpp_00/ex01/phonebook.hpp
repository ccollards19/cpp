#pragma once

#include <iostream>
#include "Contact.hpp"

using namespace std;

class Phonebook
{
	private:
		Contact	contact_stack[8];
		int	index;
	public:
		Phonebook();
		void add(void);
		void search(void);
};
