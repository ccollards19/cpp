#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
		return 1;
	Harl harl;
	harl.Harl::complain(argv[1]);
	return 0; 
}
