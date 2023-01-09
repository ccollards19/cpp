#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	Phonebook	phonebook;
	string		input;

	while(1)
	{
		cout<<"COMMANDS AVAIBLE:\t[ADD]\n\t\t\t[SEARCH]\n\t\t\t[EXIT]"<<endl;
		getline(cin, input);
		if (input.compare("ADD") == 0)
			phonebook.add();
		if (input.compare("SEARCH") == 0)
			phonebook.search();
		if (cin.eof() || cin.fail() || input.compare("EXIT") == 0)
			break;
	}
}
