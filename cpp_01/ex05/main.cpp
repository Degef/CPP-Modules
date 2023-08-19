#include "Harl.hpp"

int main( void ) {

    std::string input;
    Harl        harl;

	while (1)
    {
        std::cout << "Enter a level: (debug, info, warning, error): ";
        std::cin >> input;
		if (input.compare("exit") == 0)
			break ;
        harl.complain(input);
    };

    return EXIT_SUCCESS;
}