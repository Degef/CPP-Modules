#include <iostream>
#include <iomanip>
#include <string>

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    Contact(const std::string first, const std::string last, const std::string nick,
            const std::string phone, const std::string secret){
                firstName = first;
                lastName = last;
                nickname = nick;
                phoneNumber = phone;
                darkestSecret = secret;
            }
    //getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const; 
};

#endif
git remote add origin https://github.com/Degef/CPP-Modules-.git
git branch -M master
git push -u origin master