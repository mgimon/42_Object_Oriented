
#include <iostream>
#include <string>

void printAddresses(std::string* string, std::string* stringPTR, std::string& stringREF) {

std::cout << std::endl;
std::cout << "The memory address of string is " << *(&string) << std::endl;
std::cout << "The memory address held by the pointer is " << stringPTR << std::endl;
std::cout << "The memory address held by the reference is " << &stringREF << std::endl;
std::cout << std::endl;

}

void printValues(std::string* string, std::string* stringPTR, std::string& stringREF) {

	std::cout << std::endl;
	std::cout << "The value of string is " << *string << std::endl;
	std::cout << "The value pointed to by the pointer is " << *stringPTR << std::endl;
	std::cout << "The value pointed to by the reference is " << stringREF << std::endl;
	std::cout << std::endl;
	
}

int main(void)
{
std::string string = "HI THIS IS BRAIN";
std::string* stringPTR = &string;
std::string& stringREF = string;

printAddresses(&string, stringPTR, stringREF);
printValues(&string, stringPTR, stringREF);

return (0);

}
