#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
//default constructor 
    Fixed();
//copy constructor 
    Fixed(const Fixed& other);
// = operator overload
    Fixed& operator=(const Fixed& other);
// destructor 
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
};
