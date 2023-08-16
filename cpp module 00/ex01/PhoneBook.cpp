#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : currentContacts(0) {}

bool PhoneBook::addContact(const Contact& contact) {
    if (currentContacts < 8) {
        contacts[currentContacts++] = contact;
        return true;
    } else {
        // Replace the oldest contact with the new one
        contacts[0] = contact;
        return true;
    }
    return false;
}

Contact PhoneBook:: getContact(int index) const {
        if (index >= 0 && index < currentContacts) {
            return contacts[index];
        }
        throw std::out_of_range("Invalid index");
}

int PhoneBook::getCurrentContacts() const {
        return currentContacts;
}

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

std::string Contact::getFirstName() const {
        return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}