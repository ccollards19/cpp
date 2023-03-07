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

		void make_field(string &field , string name, int &pos);
	public:
		void set_first_name(void);
		void set_last_name(void);
		void set_nickname(void);
		void set_number(void);
		void set_darkest_secret(void);
		void display();
		void display_line(int i);
};
