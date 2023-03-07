#include "Span.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

Span::Span(unsigned int N)
{
	this->N = N;
}
Span::Span(const Span &obj)
{
	this->N = obj.N;
	this->addNumberRange(obj.vec.begin(), obj.vec.end());
}

Span::~Span()
{

}

Span &Span::operator= (Span const &old)
{
	if (this != &old)
	{
		this->N = old.N;
		this->vec = old.vec;
	}
	return *this;
}

void Span::addNumber(int nbr)
{
	if (vec.size() >= this->N)
		throw (ObjFull());
	vec.push_back(nbr);
}

void Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}	

void Span::addNumberRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}	

unsigned int Span::longestSpan()
{
	if (this->vec.size() < 2)
		throw (NoSpan());
	return (abs(	*(std::max_element(this->vec.begin(), this->vec.end())) 
			- *(std::min_element(this->vec.begin(), this->vec.end()))));
}

unsigned int Span::shortestSpan()
{
	if (this->vec.size() < 2)
		throw (NoSpan());
	std::vector<int>::iterator begin = vec.begin();
	std::vector<int>::iterator next = vec.begin();
	next++;
	std::vector<int>::iterator end = vec.end();
	unsigned int ret = -1;
	std::sort(begin, end);
	while(next != end)
	{
		if (abs(*begin - *next) < ret || ret < 0)
			ret = abs(*begin - *next);
		next++;
		begin++;
	}
	return (ret);
}

const char* Span::ObjFull::what() const throw()
{
	return("OBJECT FULL : no more values can be added");
}

const char* Span::NoSpan::what() const throw()
{
	return("NO SPAN : object has less than 2 values");
}
