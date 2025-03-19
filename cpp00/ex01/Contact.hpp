#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{

private:

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:

    Contact();
    bool isValidInput(const std::string& input);
    void setFirstName();
    void setLastName();
    void setNickName();
    void setPhoneNumber();
    void setDarkestSecret();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
