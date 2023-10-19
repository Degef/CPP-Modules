#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <exception>

Contact::Contact() : _firstName(), _lastName(), _nickname(), _phoneNumber(), _darkestSecret() {}

Contact::Contact(const std::string first, const std::string last, const std::string nick,
            const std::string phone, const std::string secret){
                _firstName = first;
                _lastName = last;
                _nickname = nick;
                _phoneNumber = phone;
                _darkestSecret = secret;
            }
Contact::~Contact(){}

std::string Contact::getFirstName() const {
        return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}


// Function to truncate and replace last displayable character with a dot
std::string truncateAndReplace(const std::string& text, size_t width) {
    if (text.size() > width) {
        return text.substr(0, width - 1) + ".";
    } else {
        return text;
    }
}

void display_contacts(PhoneBook& my_phone_book, int count)
{
    std::cout << std::setw(10) << "Index" << " | "
                << std::setw(10) << "First Name" << " | "
                << std::setw(10) << "Last Name" << " | "
                << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(50, '-') << std::endl;


   for (int i = 0; i < count; ++i) {
        std::string firstName = my_phone_book.getContact(i).getFirstName();
        std::string lastName = my_phone_book.getContact(i).getLastName();
        std::string nickname = my_phone_book.getContact(i).getNickname();

        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << std::right << truncateAndReplace(firstName, 10) << " | "
                  << std::setw(10) << std::right << truncateAndReplace(lastName, 10) << " | "
                  << std::setw(10) << std::right << truncateAndReplace(nickname, 10) << std::endl;
    }
}

void search_contact(PhoneBook& my_phone_book)
{
    int count = my_phone_book.getCurrentContacts();
    if (count == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }
	display_contacts(my_phone_book, count);
    std::cout << "Enter index of the contact to display: "<< std::flush;
	int index;
    std::string input;

    try
    {
		while (!std::getline(std::cin, input, '\n') || input.empty() || std::stoi(input) < 0 || std::stoi(input) > 8)
			std::cout << "Invalid input. Enter a valid index: " << std::flush;

		index = std::stoi(input);
        Contact contact = my_phone_book.getContact(index);
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    }
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
