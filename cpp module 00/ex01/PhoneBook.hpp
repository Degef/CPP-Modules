#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {
public:
    Contact contacts[8];
    int currentContacts;
    PhoneBook();

    bool addContact(const Contact& contact);
    Contact getContact(int index) const;
    //getters
    int getCurrentContacts() const;
};

#endif