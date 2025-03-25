#include "Harl.hpp"

int main(void)
{
	Harl harl1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "NOT_A_COMMAND"};

	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		std::cout << "Testing level " << levels[i] << std::endl;
		std::cout << std::endl;
		harl1.complain(levels[i]);
		std::cout << std::endl;
	}
	return (0);
}
