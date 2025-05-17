#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data dataStruct = {42};

	std::cout << "dataStruct memory address: " << &dataStruct << std::endl;
    uintptr_t raw = Serializer::serialize(&dataStruct);
	std::cout << "dataStruct memory address serialized: " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);

	std::cout << std::endl;

	if (ptr == &dataStruct)
		std::cout << GREEN << "The deserialization was successful" << RESET << std::endl;
	else
		std::cout << "The deserialization was unsuccessful" << std::endl;

    return (0);
}
