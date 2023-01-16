#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"<<std::endl;
}
void Harl::info( void )
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}
void Harl::warning( void )
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}
void Harl::error( void )
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::filter( void )
{
	std::cout<<"Probably complaining about insignificant problems."<<std::endl;
}

void Harl::complain( std::string level)
{
	(!(level.std::string::compare("DEBUG")) && (this->ptr = &Harl::debug)) ||
	(!(level.std::string::compare("WARNING")) && (this->ptr = &Harl::warning)) ||
	(!(level.std::string::compare("INFO")) && (this->ptr = &Harl::info)) ||
	(!(level.std::string::compare("ERROR")) && (this->ptr = &Harl::error)) ||
	(this->ptr = &Harl::filter);
	(this->*ptr)();
}
