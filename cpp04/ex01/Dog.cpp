#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	_brain = new Brain();
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog( const Dog& src ): Animal(src)
{
    *this = src;
}

Dog& Dog::operator=( const Dog& src )
{
    std::cout << "Dog copy called." << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = new Brain( *src._brain );
    }
    return *this;
}

Brain& Dog::getBrain() {
	return *_brain;
}