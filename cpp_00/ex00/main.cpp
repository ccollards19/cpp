#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
		cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<endl;
	else 
	{
		int i = 0;
		while (i < argc)
		{
			string str = argv[i];
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			cout<<str<<" ";
			i++;
		}
		cout<<endl;
	}
}
