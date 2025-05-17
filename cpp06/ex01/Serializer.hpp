#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &ref);
		Serializer& operator = (Serializer &ref);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
