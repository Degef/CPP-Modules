#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook;

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact(void);
    Contact(const std::string first, const std::string last, const std::string nick,
            const std::string phone, const std::string secret);
	~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const; 
};

void search_contact(PhoneBook& my_phone_book);
#endif
