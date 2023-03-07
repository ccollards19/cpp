#include <iostream>
#include "MutantStack.hpp"

//TODO add range test and huge range test

/*int main()
{
	int myints[] = {1,4,2,5,2,-10,20};
	int i;
	try
	{
		std::cout<<"test with vectors"<<std::endl;
		std::vector<int> vec(myints, &(myints[7]));
		Span obj(7);
		obj.addNumberRange(vec.begin(), vec.end());
		std::cout<<obj.shortestSpan()<<std::endl;
		std::cout<<obj.longestSpan()<<std::endl;
	}
	catch (const std::exception &err)
	{
		std::cout<<err.what()<<std::endl;
	}

	return 0;
}*/

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout<<"|||||||||||||||||||||||l"<<std::endl;
	while (it!= ite) {
		std::cout << *it << std::endl;
		++it; }
	it = mstack.begin();
	ite = mstack.end();
	std::cout<<"|||||||||||||||||||||||l"<<std::endl;
	while (it!= ite) {
		std::cout << *it << std::endl;
		++it; }
	std::stack<int> s(mstack);
	return 0;
}
