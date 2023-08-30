#include "Animal.hpp"

Animal::Animal() : _type("Unknown") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called with type " << type << std::endl;
}

Animal::Animal( const Animal& src )
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=( const Animal& other )
{
    std::cout << "Animal assignment operator called" << std::endl;
    if ( this != &other ) {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
        std::cout << "Animal sound" << std::endl;
}