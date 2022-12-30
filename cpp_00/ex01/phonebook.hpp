#pragma once

#include <iostream>

using namespace std;

class Contact
{
	private:
		string first_name;
		string last_name;
		string nickname;
		string number;
		string darkest_secret;

		void make_field(string &field , string name, int &pos)
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
	public:
		void set_first_name(void)
		{
			string input;
			while (input.size() == 0)
			{
				cout<<"enter first name"<<endl;
				getline(cin, input);
			}
			first_name = input;
		}

		void set_last_name(void)
		{
			string input;
			while (input.size() == 0)
			{
				cout<<"enter last name"<<endl;
				getline(cin, input);
			}
			last_name = input;
		}

		void set_nickname(void)
		{
			string input;
			while (input.size() == 0)
			{
				cout<<"enter nickname"<<endl;
				getline(cin, input);
			}
			nickname = input;
		}

		void set_number(void)
		{
			string input;
			while (input.size() == 0)
			{
				cout<<"enter number"<<endl;
				getline(cin, input);
			}
			number = input;
		}

		void set_darkest_secret(void)
		{
			string input;
			while (input.size() == 0)
			{
				cout<<"enter darkest secret"<<endl;
				getline(cin, input);
			}
			darkest_secret = input;
		}

		void display()
		{
			cout<<first_name<<endl;
			cout<<last_name<<endl;
			cout<<nickname<<endl;
			cout<<number<<endl;
			cout<<darkest_secret<<endl;
		}
		
		void display_line(int i)
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
				make_field(field1, this->first_name , f1);
				make_field(field2, this->last_name , f2);
				make_field(field3, this->nickname , f3);
				cout<<field0<<field1<<field2<<field3<<endl;
				field0 = pipel+"          "+pipel;
				
			} while (f1 < (int)this->first_name.size() 
				|| f2 < (int)this->last_name.size() 
				|| f3 < (int)this->nickname.size());
		}
};


class Phonebook
{
	private:
		Contact	contact_stack[8];
		int	index;
	public:
		Phonebook() {index = -1;}
		void add(void)
		{	
			if (index < 7)
				index++;
			contact_stack[index].set_first_name();
			contact_stack[index].set_last_name();
			contact_stack[index].set_nickname();
			contact_stack[index].set_number();
			contact_stack[index].set_darkest_secret();
		}
		void search(void)
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
				if (input.size() == 1 && isdigit(input[0]))
					i = stoi(input);
				if (i >= 0 && i <= index)
					break;
			}
			contact_stack[i].display();
		};
};


