#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Creating a Serializer object..." << std::endl;
}

Serializer::Serializer(Serializer& ref) {
	(void)ref;
	std::cout << "Copying a Serializer object..." << std::endl;
}

Serializer& Serializer::operator = (Serializer& ref) {
	if (this != &ref)
	{
		std::cout << "Assigning a Serializer object..." << std::endl;
	}
	return (*this);
}

Serializer::~Serializer() {
	std::cout << "Destroying a Serializer object..." << std::endl;
}

// ** MEMBER FUNCTIONS ** //

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
