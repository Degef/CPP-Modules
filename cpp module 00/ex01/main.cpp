#include "PhoneBook.hpp"
#include "Contact.hpp"

void add_contact(PhoneBook& my_phone_book)
{
    std::string first, last, nick, phone, secret;
    std::cout << "Enter first name: ";
    std::cin >> first;
    std::cout << "Enter last name: ";
    std::cin >> last;
    std::cout << "Enter nickname: ";
    std::cin >> nick;
    std::cout << "Enter phone number: ";
    std::cin >> phone;
    std::cout << "Enter darkest secret: ";
    std::cin >> secret;

    Contact newContact(first, last, nick, phone, secret);
    my_phone_book.addContact(newContact);
}

void search_contact(PhoneBook& my_phone_book)
{
    int count = my_phone_book.getCurrentContacts();
    if (count == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << " | "
                << std::setw(10) << "First Name" << " | "
                << std::setw(10) << "Last Name" << " | "
                << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(42, '-') << std::endl;

    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(10) << i << " | "
                    << std::setw(10) << my_phone_book.getContact(i).getFirstName() << " | "
                    << std::setw(10) << my_phone_book.getContact(i).getLastName() << " | "
                    << std::setw(10) << my_phone_book.getContact(i).getNickname() << std::endl;
    }

    std::cout << "Enter index of the contact to display: ";
    int index;
    std::cin >> index;

    try
    {
        Contact contact = my_phone_book.getContact(index);
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Invalid index." << std::endl;
    }
}

int main()
{
    PhoneBook my_phone_book;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::string command;
        std::cin >> command;

        if (command == "ADD")
            add_contact(my_phone_book);
        else if (command == "SEARCH") 
            search_contact(my_phone_book);         
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }

    return 0;
}
