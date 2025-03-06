#include "megaphone.hpp"

void printUpperCase(const char *str)
{
    for (int i = 0; str[i]; i++)
        std::cout << (char)std::toupper(str[i]);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            printUpperCase(argv[i]);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}