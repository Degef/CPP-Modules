#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
}

Fixed::Fixed(const float float_value) : _value(std::roundf(float_value * (1 << _fractionalBits))) {
}

Fixed::Fixed(const Fixed& other) {
	this->_value = other.getRawBits();
}

// Overload of << operator for output
std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint) {
    os << fixedPoint.toFloat();
    return os;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
	int int_value = _value / (1 << _fractionalBits);
	return int_value;
}

/****************************Comparison Operators*******************************/

bool Fixed::operator>(const Fixed& other) const {
	return this->_value > other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_value < other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_value != other._value;
}

/****************************Arithmetic Operators*******************************/
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

/****************************Increment Operators*******************************/

Fixed& Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int ) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator--(int ) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

/****************************Min and Max*******************************/

Fixed& Fixed::min(Fixed& first, Fixed& second){
	if (first._value < second._value)
		return first;
	return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second){
	if (first._value < second._value)
		return first;
	return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second){
	if (first._value > second._value)
		return first;
	return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second){
	if (first._value > second._value)
		return first;
	return second;
}