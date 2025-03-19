#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string input;
    PhoneBook   phonebook;
    Contact     contact;
    int         number;
    int         n = 0;

    while (true)
    {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, input))
            exit(1);
        if (input == "ADD")
        {
            if (n > 7)
                n = 0;
            phonebook.addContact(contact);
            n++;
        }
        else if (input == "SEARCH")
        {
            phonebook.displayDetails();
            std::cout << std::endl;
            std::cout << "Please enter which index to display:" << std::endl;
            if (!std::getline(std::cin, input))
                exit(1);
            std::stringstream(input) >> number;
            if (number <= n)
                phonebook.displayIndex(number);
            else
                std::cout << "Error: No entry found!" << std::endl;
        }
        else if (input == "EXIT")
            break;
        else
            std::cout << "Invalid command!" << std::endl;
    }


    return 0;
}
