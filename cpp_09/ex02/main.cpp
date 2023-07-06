#include "PmergeMe.hpp"

void ext(int exit_status, std::string msg)
{
	std::cout<<msg<<std::endl;
	exit(exit_status);
}

int main(int ac, char **av)
{
	if (ac < 2)
		ext(1, "Error: No args");
	std::cout<<"unsorted : ";
	for (int i = 1; i < ac; i++)
	{
		for (int  j = 0; av[i][j]; j++)
			if (!std::isdigit(av[i][j]))
				ext(1, "\nError: Non int arg");
		std::cout<<" "<<av[i];
	}
	std::cout<<std::endl;

	std::clock_t vec_count;
	std::vector<int> vec;
	std::clock_t lst_count;
	std::list<int> lst;
	vec_count = sort_vector(av, vec);
	lst_count = sort_list(av, lst);
	std::cout<<"sorted : ";
	for (std::vector<int>::iterator it = vec.begin() ; it != vec.end(); it++)
		std::cout<<" "<<(*it);
	std::cout<<std::endl;
	//std::cout<<"sorted : ";
	//for (std::list<int>::iterator it = lst.begin() ; it != lst.end(); it++)
	//	std::cout<<" "<<(*it);
	//std::cout<<std::endl;
	std::cout<<"Time to process a range of "<<(ac-1)<<" elements with a vector : "
	<<vec_count<<" processor time units"<<std::endl;
	std::cout<<"Time to process a range of "<<(ac-1)<< " elements with a list : "
	<<lst_count<<" processor time units"<<std::endl;
	return (0);
}
