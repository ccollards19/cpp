#pragma once
#include <iostream>
#include <exception>
#include <vector>

class Span
{
	private :
		unsigned int N;
		std::vector<int> vec;
	public :
		Span(unsigned int N);
		Span(const Span &obj);

		~Span();

		Span &operator= (Span const &old);

		void addNumber(int nbr);
		void addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void addNumberRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class ObjFull : public std::exception
		{
			const char* what() const throw() ;
		};

		class NoSpan : public std::exception
		{
			const char* what() const throw() ;
		};
};
