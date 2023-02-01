#include "ScalarConvertor.hpp"

int ScalarConvertor::custom_convertor_int(str);
{

}

float ScalarConvertor::custom_convertor_float(str);
{

}

double ScalarConvertor::custom_convertor_double(str);
{

}

char ScalarConvertor::custom_convertor_char(str);
{

}

void ScalarConvertor::convert (std::string str)
{
	if ()
	{	
		std::cout<<"int : "<<custom_convertor_int(str)<<std::endl;
		std::cout<<"float : "<<static_cast<float>(str)<<std::endl;
		std::cout<<"double : "<<static_cast<double>(str)<<std::endl;
		std::cout<<"char : "<<static_cast<char>(str)<<std::endl;
	}
	else if ()
	{	
		std::cout<<"float : "<<custom_convertor_float(str)<<std::endl;
		std::cout<<"int : "<<static_cast<int>(str)<<std::endl;
		std::cout<<"double : "<<static_cast<double>(str)<<std::endl;
		std::cout<<"char : "<<static_cast<char>(str)<<std::endl;
	}
	else if ()
	{	
		std::cout<<"double : "<<custom_convertor_double(str)<<std::endl;
		std::cout<<"int : "<<static_cast<int>(str)<<std::endl;
		std::cout<<"float : "<<static_cast<float>(str)<<std::endl;
		std::cout<<"char : "<<static_cast<char>(str)<<std::endl;
	}
	else if ()
	{	
		std::cout<<"char : "<<custom_convertor_char(str)<<std::endl;
		std::cout<<"int : "<<static_cast<int>(str)<<std::endl;
		std::cout<<"float : "<<static_cast<float>(str)<<std::endl;
		std::cout<<"double : "<<static_cast<double>(str)<<std::endl;
	}
	else
		throw ScalarConvertor::NotValidTypeException;
}

///////////////////////////////////////////////////

const char *ScalarConvertor::NotValidTypeException::what() const throw()
{
	return ("NotValidationTypeException");
}

