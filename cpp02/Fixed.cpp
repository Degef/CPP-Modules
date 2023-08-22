    #include "Fixed.hpp"

    Fixed::Fixed() : value(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    Fixed::Fixed(const Fixed& other) : value(other.value) {
        std::cout << "Copy constructor called" << std::endl;
    }
