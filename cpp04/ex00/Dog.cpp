#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
    std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
