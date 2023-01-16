#pragma once
#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void filter( void );
	public:	
		void complain( std::string level);
		void (Harl::*ptr)(void);
};
