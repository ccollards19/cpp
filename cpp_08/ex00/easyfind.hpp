#pragma once
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &lst, int nbr)
{
	typename T::iterator lst_begin = lst.begin();
	typename T::iterator lst_end = lst.end();
	typename T::iterator it;

	for (it = lst_begin; it != lst_end; it++)
	{
		if (*it == nbr)
			return (it);
	}
	return (it);
}
