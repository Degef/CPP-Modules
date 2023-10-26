#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG: This is just a for problem diagnosis purposes." << std::endl;
}

void Harl::info() {
        std::cout << "INFO: Just letting you know." << std::endl;
    }

void Harl::warning() {
	std::cout << "WARNING: This could be a problem." << std::endl;
}

void Harl::error() {
	std::cout << "ERROR: Something went wrong." << std::endl;
}

void Harl::complain(std::string level){
	const int kLevels = 4;
	int int_level = 0;

	std::string complainLevels[kLevels] = {"DEBUG", "INFO", "WARNING",	"ERROR"};
	while (int_level < kLevels && complainLevels[int_level] != level)
		int_level++;
	switch (int_level)
	{
	case 0:
		debug();
		// Intentional fallthrough
	case 1:
		info();
		// Intentional fallthrough
	case 2:
		warning();
		// Intentional fallthrough
	case 3:
		error();
		break;
	default:
		std::cerr << "Invalid complain level, (DEBUG, INFO, WARNING, ERROR)" << std::endl;
		break;
	}
}
