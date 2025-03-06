#include "Contact.hpp"

Contact::Contact() {

}

bool Contact::isValidInput(const std::string& input) {
    return !input.empty() && input.find_first_not_of(" \t\n\r") != std::string::npos;
}

void Contact::setFirstName()
{
    std::string input;

    while (true)
    {
        std::cout << "Please enter the First Name:" << std::endl;
        std::getline(std::cin, input);

        if (isValidInput(input))
            break ;

        std::cout << "Input cannot be empty!" << std::endl;
        std::cout << std::endl;
    }
    this->firstName = input;
}

void Contact::setLastName()
{
    std::string input;

    while (true)
    {
        std::cout << "Please enter the Last Name:" << std::endl;
        std::getline(std::cin, input);

        if (isValidInput(input))
            break ;

        std::cout << "Input cannot be empty!" << std::endl;
        std::cout << std::endl;
    }
    this->lastName = input;
}

void Contact::setNickName()
{
    std::string input;

    while (true)
    {
        std::cout << "Please enter the Nick Name:" << std::endl;
        std::getline(std::cin, input);

        if (isValidInput(input))
            break ;

        std::cout << "Input cannot be empty!" << std::endl;
        std::cout << std::endl;
    }
    this->nickName = input;
}

void Contact::setPhoneNumber()
{
    std::string input;

    while (true)
    {
        std::cout << "Please enter the Phone Number:" << std::endl;
        std::getline(std::cin, input);

        if (isValidInput(input))
            break ;

        std::cout << "Input cannot be empty!" << std::endl;
        std::cout << std::endl;
    }
    this->phoneNumber = input;
}

void Contact::setDarkestSecret()
{
    std::string input;

    while (true)
    {
        std::cout << "Please enter the Darkest Secret:" << std::endl;
        std::getline(std::cin, input);

        if (isValidInput(input))
            break ;

        std::cout << "Input cannot be empty!" << std::endl;
        std::cout << std::endl;
    }
    this->darkestSecret = input;
}

std::string Contact::getFirstName() const
{
    return this->firstName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

std::string Contact::getNickName() const
{
    return this->nickName;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}
