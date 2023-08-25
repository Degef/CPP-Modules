#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y):	_x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other): _x(other._x), _y(other._y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
	if (this != &other)
	{
		(Fixed) this->_x = other._x;
		(Fixed) this->_y = other._y;
	}
	return *this;
}

Fixed Point::get_x(void ) const {
	return _x;
}

Fixed Point::get_y(void ) const {
	return _y;
}