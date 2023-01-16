#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "str" << "addr: " << &str << " value: " << str << std::endl;
	std::cout << "str" << "addr: " << &stringPTR << " value: " << stringPTR << std::endl;
	std::cout << "str" << "addr: " << &stringREF << " value: " << stringREF << std::endl;
}
