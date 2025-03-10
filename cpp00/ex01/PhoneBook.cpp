#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : addIndex(0), contactCount(0) {}

void PhoneBook::addContact(Contact contact)
{
    // fills with first 8 contacts
    if (contactCount < 8)
    {
        contacts[contactCount] = contact;
        contactCount++;
    }
    // replaces up until 8 and resets to 0
    else
    {
        contacts[addIndex] = contact;
        addIndex = (addIndex + 1) % 8;
    }
}


void PhoneBook::displayDetails() const
{
    std::string truncate;

    std::cout << "|";
    std::cout << std::setw(10) << std::right << "Index";
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "FirstName";
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "LastName";
    std::cout << "|";
    std::cout << std::setw(10) << std::right << "NickName";
    std::cout << "|";
    std::cout << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << "|";
        std::cout << std::setw(10) << std::right << i;
        std::cout << "|";
        if (this->contacts[i].getFirstName().length() >= 10)
        {
            truncate = this->contacts[i].getFirstName().substr(0, 10);
            truncate[truncate.size() - 1] = '.';
        }
        else
            truncate = this->contacts[i].getFirstName();
        std::cout << std::setw(10) << std::right << truncate;
        std::cout << "|";
        if (this->contacts[i].getLastName().length() >= 10)
        {
            truncate = this->contacts[i].getLastName().substr(0, 10);
            truncate[truncate.size() - 1] = '.';
        }
        else
            truncate = this->contacts[i].getLastName();
        std::cout << std::setw(10) << std::right << truncate;
        std::cout << "|";
        if (this->contacts[i].getNickName().length() >= 10)
        {
            truncate = this->contacts[i].getNickName().substr(0, 10);
            truncate[truncate.size() - 1] = '.';
        }
        else
            truncate = this->contacts[i].getNickName();
        std::cout << std::setw(10) << std::right << truncate;
        std::cout << "|";
        std::cout << std::endl;
    }
}

void PhoneBook::displayIndex(int n) const
{
    std::string line;
    
    if (n < 0 || n >= contactCount)
    {
        std::cout << "Error: Index is out of range" << std::endl;
        return ;
    }
    line = contacts[n].getFirstName();
    std::cout << "First Name -> " << line;
    std::cout << std::endl;

    line = contacts[n].getLastName();
    std::cout << "Last Name -> " << line;
    std::cout << std::endl;

    line = contacts[n].getNickName();
    std::cout << "Nick Name -> " << line;
    std::cout << std::endl;

    line = contacts[n].getPhoneNumber();
    std::cout << "Phone Number -> " << line;
    std::cout << std::endl;

    line = contacts[n].getDarkestSecret();
    std::cout << "Darkest Secret -> " << line;
    std::cout << std::endl;
}

