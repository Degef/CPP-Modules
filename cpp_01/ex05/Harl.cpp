#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "Debug: This is just a for dubugging purposes." << std::endl;
}
void Harl::info() {
        std::cout << "Info: Just letting you know." << std::endl;
    }

void Harl::warning() {
	std::cout << "Warning: This could be a problem." << std::endl;
}

void Harl::error() {
	std::cout << "Error: Something went wrong." << std::endl;
}

void Harl::complain(std::string level){
	const int kLevels = 4;
	std::string complainLevels[kLevels] = {"debug", "info", "warning",	"error"};

	t_func functions[kLevels] = {&Harl::debug, &Harl::debug, &Harl::info, &Harl::warning};

	for (int i = 0; i < kLevels; i++) {
		if (complainLevels[i].compare(level) == 0) {
			(this->*(functions[i]))();
			return;
		}
	}
	std::cerr << "Error: Invalid complain level" << std::endl;
}