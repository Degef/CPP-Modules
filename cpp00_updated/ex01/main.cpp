#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook my_phone_book;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::string command = "";
        std::getline(std::cin, command);

        if (command == "ADD")
            add_contact(my_phone_book);
        else if (command == "SEARCH") 
            search_contact(my_phone_book);         
        else if (command == "EXIT")
            break;
		else if (std::cin.eof()){
			break ;
		}
		else if (command.empty())
			continue ;
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}
