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
		Harl::debug();
	case 1:
		Harl::info();
	case 2:
		Harl::warning();
	case 3:
		Harl::error();
		break;
	default:
		std::cerr << "Invalid complain level, (DEBUG, INFO, WARNING, ERROR)" << std::endl;
		break;
	}
}