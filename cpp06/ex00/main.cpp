
#include "ScalarConverter.hpp"

int	valid(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\n')
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "The program expects one (1) parameter!" << RESET << std::endl;
		return (1);
	}
	if (!valid(argv[1]))
	{
		std::cout << RED << "The program expects a valid parameter!" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
