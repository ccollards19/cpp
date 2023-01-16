#include <iostream>
#include <fstream>

void s_edit(std::string input, char *str_in, char *str_out, std::ofstream &dest)
{
	static std::string buffer;
	int i = 0;
	std::string comp_str = str_in;
	char *str_in_save = str_in;

	while(input[i])
	{
		if (input[i] == *str_in)
		{
			buffer += *str_in;
			str_in++;
		}
		else if (input[i] != *str_in)
		{
			buffer += input[i];
			dest<<buffer;
			buffer.std::string::clear();
			str_in = str_in_save;
		}
		if (buffer.std::string::compare(comp_str) == 0)
		{
			dest<<str_out;
			buffer.std::string::clear();
			str_in = str_in_save;
		}
		i++;
	}
}

int main(int argc, char **argv) 
{
	if (argc != 4)
	{
		std::cerr<<"error : number of arguments"<<std::endl;
		return 1;
	}
	if (*argv[2] == '\0' || *argv[3] == '\0')
	{
		std::cerr<<"error : empty argument"<<std::endl;
		return 1;
	}
	std::string	filename = argv[1];
	std::string	input;
	std::ifstream	src(filename);
	std::ofstream	dest((filename+".dest"));

	if (!src.std::ifstream::good())
	{
		std::cerr<<"error : failed to open file"<<std::endl;
		return 1;
	}
	
	while (std::getline(src, input))
	{
		s_edit(input, argv[2], argv[3], dest);
		dest<<std::endl;
		input.std::string::clear();
	}
	src.close();
	dest.close();
	return 0; 
}
