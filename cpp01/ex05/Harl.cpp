#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "This is the private function debug. This function outputs the bugs." << std::endl;
}

void Harl::info(void) {
	std::cout << "This is the private function info. This function outputs the info." << std::endl;
}

void Harl::warning(void) {
	std::cout << "This is the private function warning. This function outputs the warnings." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is the private function error. This function outputs the errors." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    void (Harl::*complaints[])(void) =
	{
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*complaints[i])();
            return ;
        }
    }
    std::cout << "Error: accepted levels are only 'DEBUG', 'INFO', 'WARNING' or 'ERROR'" << std::endl;
}
