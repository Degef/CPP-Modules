#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
//default constractor 
    Fixed();

    Fixed(const Fixed& other) : value(other.value) {
        std::cout << "Copy constructor called" << std::endl;
    }

    Fixed& operator=(const Fixed& other) {
        if (this != &other) {
            value = other.value;
            std::cout << "Copy assignment operator called" << std::endl;
        }
        return *this;
    }

    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }

    int getRawBits() const {
        std::cout << "getRawBits member function called" << std::endl;
        return value;
    }

    void setRawBits(int const raw) {
        value = raw;
    }
};