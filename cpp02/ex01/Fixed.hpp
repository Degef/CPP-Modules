#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
//default constructor 
    Fixed();
//copy constructor 
    Fixed(const Fixed& other);
// = operator overload
    Fixed& operator=(const Fixed& other);
// destructor 
    ~Fixed();
	Fixed(const int value);
	Fixed(const float float_value);


    int getRawBits() const;
    void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);
};