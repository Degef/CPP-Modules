#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Cat::Cat( const Cat& other ): Animal(other)
{
    *this = other;
}

Cat& Cat::operator=( const Cat& other )
{
    std::cout << "Cat copy called." << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain( *other._brain );
    }
    return *this;
}
Brain& Cat::getBrain() {
	return *_brain;
}
