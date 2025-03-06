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
        std::getline(std::cin, input);

        if (input == "ADD")
        {
            if (n > 7)
                n = 0;
            contact.setFirstName();
            contact.setLastName();
            contact.setNickName();
            contact.setPhoneNumber();
            contact.setDarkestSecret();
            phonebook.addContact(contact);
            n++;
        }
        else if (input == "SEARCH")
        {
            phonebook.displayDetails();
            std::cout << std::endl;
            std::cout << "Please enter which index to display:" << std::endl;
            std::getline(std::cin, input);
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
