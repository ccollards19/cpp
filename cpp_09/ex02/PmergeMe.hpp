#pragma once
#include <iostream>
#include <ctime>
#include <cstring>
#include <cctype>
#include <vector>
#include <list>
#include <algorithm>

typedef struct pair 
{
	int main_val;
	int pending_val;
} t_pair;

bool arr_comparer (const t_pair &a, const t_pair &b);
std::clock_t sort_vector(char **av, std::vector<int> &vec);
std::clock_t sort_list(char **av, std::list<int> &lst);

