#include "PmergeMe.hpp"

bool arr_comparer (const t_pair &a, const t_pair &b)
{
	return (a.main_val < b.main_val);
}

void swap_and_sort(int &a, int &b)
{
	if (a >= b)
		return ;
	int tmp = a;
	a = b;
	b = tmp;
}

std::clock_t sort_vector(char **av, std::vector<int> &vec)
{
	std::clock_t start = std::clock();
	int size = 1;
	std::vector<t_pair> pair_tab;
	///////////////////////////////////////
	///split into sorted pairs
	while(av[size] && av[size + 1])
	{
		t_pair pair;
		pair.main_val = atoi(av[size]);
		size++;
		pair.pending_val = atoi(av[size]);
		size++;
		swap_and_sort(pair.main_val, pair.pending_val);
		pair_tab.insert(std::lower_bound(pair_tab.begin(), pair_tab.end(), pair, arr_comparer), pair);
	}
	if (av[size])
	{
		t_pair pair;
		pair.main_val = -1;
		pair.pending_val = atoi(av[size]);
		pair_tab.push_back(pair);
	}
	////////////////////////////////////
	///insert pending values then push_back main values
	for (std::vector<t_pair>::iterator it = pair_tab.begin() ; it != pair_tab.end(); it++)
	{
		vec.insert(std::lower_bound(vec.begin(), vec.end(), (*it).pending_val), (*it).pending_val);
		vec.push_back((*it).main_val);
	}
	////////////////////////////////////
	/// if last -1 remove it
	if (vec.back() == -1)
		vec.pop_back();
	return (std::clock() - start);
}

std::clock_t sort_list(char **av, std::list<int> &lst)
{
	std::clock_t start = std::clock();
	int size = 1;
	std::list<t_pair> pair_tab;
	///////////////////////////////////////
	///split into sorted pairs
	while(av[size] && av[size + 1])
	{
		t_pair pair;
		pair.main_val = atoi(av[size]);
		size++;
		pair.pending_val = atoi(av[size]);
		size++;
		swap_and_sort(pair.main_val, pair.pending_val);
		pair_tab.insert(std::lower_bound(pair_tab.begin(), pair_tab.end(), pair, arr_comparer), pair);
	}
	if (av[size])
	{
		t_pair pair;
		pair.main_val = -1;
		pair.pending_val = atoi(av[size]);
		pair_tab.push_back(pair);
	}
	////////////////////////////////////
	///insert pending values then push_back main values
	for (std::list<t_pair>::iterator it = pair_tab.begin() ; it != pair_tab.end(); it++)
	{
		lst.insert(std::lower_bound(lst.begin(), lst.end(), (*it).pending_val), (*it).pending_val);
		lst.push_back((*it).main_val);
	}
	////////////////////////////////////
	/// if last -1 remove it
	if (lst.back() == -1)
		lst.pop_back();
	return (std::clock() - start);
}

