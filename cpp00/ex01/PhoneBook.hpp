#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <string>
#include <sstream>
#include "Contact.hpp"


class PhoneBook
{

private:

    Contact contacts[8];
    int addIndex;
    int contactCount;

public:

    PhoneBook();
    int  getContactCount();
    void addContact(Contact contact);
    void displayDetails() const;
    void displayIndex(int n) const;
};

#endif

