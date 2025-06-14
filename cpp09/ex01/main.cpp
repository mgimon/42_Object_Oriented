#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN myCalculator;

	if (argc != 2)
		return (std::cerr << RED << "One (1) argument is expected!" << RESET << std::endl, 1);
	
	if (!myCalculator.parseStr(argv[1]))
		return (1);

	std::cout << GREEN << "The result is: " << RESET << myCalculator.getResult() << std::endl;
}
