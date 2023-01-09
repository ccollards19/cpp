#include <iostream>
#include "Contact.hpp"

using namespace std;

void Contact::make_field(string &field , string name, int &pos)
{
	string pipel = "|";		
	if (pos > (int)(name.size()))
	{
		field = "          "+pipel;
		return;
	}
	field = name.substr(pos, 10);
	string space((10 - (int)field.size()), ' ');
	field = space+field+pipel;
	pos+=10;
	if (((int)((name).size()) - pos) > 0)
	{
		field.replace(9, 1, ".");
		pos--;
	}
}

void Contact::set_first_name(void)
{
	string input;
	while (input.size() == 0)
	{
		cout<<"enter first name"<<endl;
		getline(cin, input);
		if (cin.eof() || cin.fail())
			exit(1);
	}
	first_name = input;
}

void Contact::set_last_name(void)
{
	string input;
	while (input.size() == 0)
	{
		cout<<"enter last name"<<endl;
		getline(cin, input);
		if (cin.eof() || cin.fail())
			exit(1);
	}
	last_name = input;
}

void Contact::set_nickname(void)
{
	string input;
	while (input.size() == 0)
	{
		cout<<"enter nickname"<<endl;
		getline(cin, input);
		if (cin.eof() || cin.fail())
			exit(1);
	}
	nickname = input;
}

void Contact::set_number(void)
{
	string input;
	while (input.size() == 0)
	{
		cout<<"enter number"<<endl;
		getline(cin, input);
		if (cin.eof() || cin.fail())
			exit(1);
	}
	number = input;
}

void Contact::set_darkest_secret(void)
{
	string input;
	while (input.size() == 0)
	{
		cout<<"enter darkest secret"<<endl;
		getline(cin, input);
		if (cin.eof() || cin.fail())
			exit(1);
	}
	darkest_secret = input;
}

void Contact::display(void)
{
	cout<<first_name<<endl;
	cout<<last_name<<endl;
	cout<<nickname<<endl;
	cout<<number<<endl;
	cout<<darkest_secret<<endl;
}

void Contact::display_line(int i)
{
	int f1 = 0;
	int f2 = 0;
	int f3 = 0;
	string pipel = "|";		
	string field0 = pipel+"         "+to_string(i)+pipel;
	string field1;
	string field2;
	string field3;

	do
	{
		make_field(field1, first_name , f1);
		make_field(field2, last_name , f2);
		make_field(field3, nickname , f3);
		cout<<field0<<field1<<field2<<field3<<endl;
		field0 = pipel+"          "+pipel;

	} while (f1 < (int)first_name.size() 
			|| f2 < (int)last_name.size() 
			|| f3 < (int)nickname.size());
}
