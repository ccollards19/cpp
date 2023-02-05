#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr<<"wrong number of arguments"<<::std::endl;
		return 1;
	}
	std::string input(argv[1]);
	try
	{
		ScalarConverter::convert(input);
	}
	catch (std::exception &err)
	{
		std::cerr<<err.what()<<::std::endl;
	}
}
