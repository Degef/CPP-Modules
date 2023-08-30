#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}