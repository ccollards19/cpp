#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "str\t" << "addr: " << &str << " value: " << str << std::endl;
	std::cout << "strptr\t" << "addr: " << &stringPTR << " value: " << stringPTR << std::endl;
	std::cout << "strref\t" << "addr: " << &stringREF << " value: " << stringREF << std::endl;
}
