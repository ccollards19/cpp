#pragma once
#include "iostream"

struct Data
{
	std::string content;
};

class Serializer
{
	private :
		Serializer();
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
