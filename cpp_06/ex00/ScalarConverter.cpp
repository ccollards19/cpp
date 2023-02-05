#include "ScalarConverter.hpp"
#include <cmath>
#include <cfloat>

const char *ScalarConverter::ImpossibleConvertion::what() const throw()
{
	return ("ImpossibleConvertion");
}

static int get_type(const char *str)
{
	int i = 0;
	int dot = 0;
	int f = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '.')
			dot++;
		else if (!std::isdigit(str[i]))
			return 0;
		i++;
	}
	if (str[i] == 'f')
		f++;
	if (dot == 0 && f == 0 && (std::isdigit(str[i]) || str[i] == 'f'))
		return 1;
	else if (f == 1)
		return 2;
	else if (dot == 1 && f == 0)
		return 3;
	else if (str[i] && i == 0)
		return 4;
	return 0;
}

void ScalarConverter::convert (std::string str)
{
	const char *str_c = str.std::string::c_str();
	int typ = get_type(str_c);
	
	if (!str.std::string::compare("nan"))
	{
		std::cout<<"int : impossible"<<std::endl;
		std::cout<<"float : "<<str<<"f" <<std::endl;
		std::cout<<"double : "<<str<<std::endl;
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (!str.std::string::compare("nanf"))
	{
		std::cout<<"int : impossible"<<std::endl;
		std::cout<<"float : "<<str<<std::endl;
		std::cout<<"double : "<<std::strtod("NAN", NULL)<<std::endl;
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (!str.std::string::compare("+inf"))
	{
		std::cout<<"int : impossible"<<std::endl;
		std::cout<<"float : "<<str<<"f" <<std::endl;
		std::cout<<"double : "<<str<<std::endl;
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (!str.std::string::compare("-inf"))
	{
		std::cout<<"int : impossible"<<std::endl;
		std::cout<<"float : "<<str<<"f" <<std::endl;
		std::cout<<"double : "<<str<<std::endl;
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (!str.std::string::compare("+inff"))
	{
		std::cout<<"int : impossible"<<std::endl;
		std::cout<<"float : "<<str<<std::endl;
		std::cout<<"double : "<<std::strtod("+INF", NULL)<<std::endl;
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (!str.std::string::compare("-inff"))
	{
		std::cout<<"int : impossible"<<std::endl;
		std::cout<<"float : "<<str<<std::endl;
		std::cout<<"double : "<<std::strtod("-INF", NULL)<<std::endl;
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (typ == 1)
	{
		long val = std::strtol(str_c, NULL, 10);
		if (val > INT_MAX || val < INT_MIN)
			std::cout<<"int : overflow"<<std::endl;
		else
			std::cout<<"int : "<<static_cast<int>(val)<<std::endl;
		std::cout<<"float : "<<static_cast<float>(val)<<"f"<<std::endl;
		std::cout<<"double : "<<static_cast<double>(val)<<std::endl;
		std::cout<<"char : '"<<static_cast<char>(val)<<"'"<<std::endl;
	}
	else if (typ == 2)
	{	
		double val = std::strtod(str_c, NULL);
		if (val > FLT_MAX || val < FLT_MIN)
			std::cout<<"float : overflow"<<std::endl;
		else
			std::cout<<"float : "<<static_cast<float>(val)<<"f"<<std::endl;
		std::cout<<"int : "<<static_cast<int>(val)<<std::endl;
		std::cout<<"double : "<<static_cast<double>(val)<<std::endl;
		std::cout<<"char : '"<<static_cast<char>(val)<<"'"<<std::endl;
	}
	else if (typ == 3)
	{	
		double val = std::strtod(str_c, NULL);
		if (val == HUGE_VAL)
			std::cout<<"double : overflow"<<std::endl;
		else	
			std::cout<<"double : "<<static_cast<double>(val)<<std::endl;
		std::cout<<"int : "<<static_cast<int>(val)<<std::endl;
		std::cout<<"float : "<<static_cast<float>(val)<<"f"<<std::endl;
		std::cout<<"char : '"<<static_cast<char>(val)<<"'"<<std::endl;
	}
	else if (typ == 4)
	{	
		char val = str[0];
		if (std::isprint(val))
			std::cout<<"char : '"<<val<<"'"<<std::endl;
		else	
			std::cout<<"char : non printable"<<std::endl;
		std::cout<<"int : "<<static_cast<int>(val)<<std::endl;
		std::cout<<"float : "<<static_cast<float>(val)<<"f"<<std::endl;
		std::cout<<"double : "<<static_cast<double>(val)<<std::endl;
	}
	else
		throw ImpossibleConvertion();
}
