#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"


class PhoneBook {

private:
    static int currentContacts;

public:
    Contact contacts[8];
    PhoneBook();
    ~PhoneBook();

    bool addContact(const Contact& contact);
    Contact getContact(int index) const;

    int getCurrentContacts() const;
};

void add_contact(PhoneBook& my_phone_book);
#endif