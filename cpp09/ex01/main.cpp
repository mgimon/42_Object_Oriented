#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN myCalculator;

	if (argc != 2)
		return (std::cerr << RED << "One (1) argument is expected!" << RESET << std::endl, 1);
	std::string	argv1 = argv[1];
	if (argv1.empty())
		return (std::cerr << RED << "Please, introduce a valid operation!" << RESET << std::endl, 1);
	
	if (!myCalculator.executeStr(argv[1]))
		return (1);

	std::cout << GREEN << "Output: " << RESET << myCalculator.getResult() << std::endl;
}
