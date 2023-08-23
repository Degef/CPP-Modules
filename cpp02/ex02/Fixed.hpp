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
	bool operator>(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed& min(Fixed& first, Fixed& second);
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);
};
