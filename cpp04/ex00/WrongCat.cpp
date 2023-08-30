#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound" << std::endl;
}
