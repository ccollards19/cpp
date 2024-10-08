#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook() {index = -1; current = -1;}

void Phonebook::add(void)
{
	if (index < 7) 
		index++;
	if (current < 7) 
		current++;
	else
		current = 0;
	contact_stack[current].set_first_name();
	contact_stack[current].set_last_name();
	contact_stack[current].set_nickname();
	contact_stack[current].set_number();
	contact_stack[current].set_darkest_secret();
}

void Phonebook::search(void)
{
	int i = 0;
	string input;
	string border(45, '-');
	cout<<border<<endl;
	while (i <= index)
	{
		contact_stack[i].display_line(i);
		i++;
	}
	cout<<border<<endl;
	i = -1;
	while (1)
	{
		cout<<"enter index"<<endl;
		getline(cin, input);
		if (cin.eof() || cin.fail())
			exit(1);
		if (input.size() == 1 && isdigit(input[0]))
			i = static_cast<int>(strtoul(input.c_str(), NULL, 10));
		if (i >= 0 && i <= index)
			break;
	}
	contact_stack[i].display();
}
