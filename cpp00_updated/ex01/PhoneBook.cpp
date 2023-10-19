#include "PhoneBook.hpp"
#include "Contact.hpp"

//default constructor
PhoneBook::PhoneBook() {}
//destactor 
PhoneBook::~PhoneBook() {}

int PhoneBook:: currentContacts = 0;

bool PhoneBook::addContact(const Contact& contact) {
    if (currentContacts < 8) {
        contacts[currentContacts++] = contact;
        return true;
    } else {
        // Replace the oldest contact with the new one
        contacts[8 % currentContacts++] = contact;
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

std::string getInput(std::string str) {
    std::string input;
    bool valid = false;

    while (!valid) {
        std::cout << str;
        if (std::getline(std::cin, input)){
            if (!input.empty())
                valid = true;
            else
                std::cout << "Invalid input; please try again." << std::endl;
        }
		else {
            if (std::cin.eof()) 
				exit (0);
			else {
                std::cin.clear();
                std::cout << "An error occurred. Please try again." << std::endl;
            }
        }
    }
    return input;
}

void add_contact(PhoneBook& my_phone_book)
{
    std::string first, last, nick, phone, secret;

    first = getInput("Enter first name: ");
    last = getInput("Enter last name: ");
    nick = getInput("Enter nickname: ");
    phone = getInput("Enter phone number: ");
	secret = getInput("Enter darkest secret: ");

    Contact newContact(first, last, nick, phone, secret);
    my_phone_book.addContact(newContact);
}
