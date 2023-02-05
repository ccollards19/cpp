#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void)
{
	Base *ret = NULL; 
	srand(time(NULL));
	int n = rand() % 3 + 1;
	if (n == 1)
	{
		std::cout << "new A" << std::endl;
		return (new A);
	}
	if (n == 2)
	{
		std::cout << "new B" << std::endl;
		return (new B);
	}
	if (n == 3)
	{
		std::cout << "new C" << std::endl;
		return (new C);
	}
	return ret;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout<<"A"<<std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout<<"B"<<std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout<<"C"<<std::endl;
	else
		std::cout<<"Failed"<<std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout<<"A"<<std::endl;
		return ;
	}
	catch (std::exception &err) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout<<"B"<<std::endl;
		return ;
	}
	catch (std::exception &err) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
		return ;
	}
	catch (std::exception &err) {}
	std::cout<<"Failed"<<std::endl;
}

int main(int argc, char **argv) 
{
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
}
