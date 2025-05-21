#include "Array.hpp"

int main(void) {
    try {
        Array<std::string> myArray(5);
        myArray[2] = "hola";
        for (unsigned int i = 0; i < 5; i++)
        {
            std::cout << myArray[i] << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception caught: " << RESET << e.what() << RED << " - accessing invalid elements!" << RESET << std::endl;
    }

    return (0);
}