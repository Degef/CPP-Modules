#include "Harl.hpp"

int main( void ) {

    std::string input;
    Harl        harl;

	while (1)
    {
        std::cout << "Enter a level: (DEBUG, INFO, WARNING, ERROR): ";
        std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || (std::cin.eof()))
			break ;
        harl.complain(input);
    };

    return EXIT_SUCCESS;
}