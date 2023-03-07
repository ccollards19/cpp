#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T *tab;
		size_t size;
	public:
		class WrongIndex : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return("Wrong index");
				}
		};

		Array()
		{
			std::cout << "Default constructor called" << std::endl;
			size = 0;
			tab = NULL;
		}

		Array(size_t n)
		{
			std::cout << "Assignement constructor called" << std::endl;
			size = n;
			tab = NULL;
			if (n)
				tab = new T[n];
		}

		Array(const Array<T> & obj)
		{
			std::cout << "Copy constructor called" << std::endl;
			size = obj.len();
			tab = new T[size];
			for (size_t i = 0; i < size; i++)
				tab[i] = obj.tab[i];
		}

		Array<T> & operator=(Array<T> const & obj)
		{
			if (obj.len() && tab)
				delete[] tab;
			size = obj.len();
			tab = new T[size];
			for (size_t i = 0; i < size; i++)
				tab[i] = obj.tab[i];
			return *this;
		}

		T & operator[](int index)
		{
			if (index >= size || index < 0)
				throw WrongIndex();
			return tab[index];
		}

		~Array()
		{
			if (size && tab)
				delete[] tab;
			size = 0;
		}
		
		size_t len() const 
		{
			return size;
		}

		void display()
		{
			for (size_t i = 0; i < size; i++)
				std::cout << tab[i] << std::endl;
		}

};
