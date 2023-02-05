#pragma once
#include "iostream"

class ScalarConverter
{
	private :
		ScalarConverter();
	public :
		static void convert(std::string convert);
		class ImpossibleConvertion : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
