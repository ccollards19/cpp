#include "Serializer.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr<<"wrong number of arguments"<<::std::endl;
		return 1;
	}
	std::string input(argv[1]);
	Data data;
	data.content = input;
	Data *data_ptr = &data;
	uintptr_t ret = Serializer::serialize(data_ptr);

	std::cout<<"address of data		"<<&data<<std::endl;
	std::cout<<"value of data_ptr	"<<data_ptr<<std::endl;
	std::cout<<"return of serialize	"<<ret<<std::endl;
	std::cout<<"return of deserialize	"<<Serializer::deserialize(ret)<<std::endl;
}
