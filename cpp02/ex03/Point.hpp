#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Fixed get_x( void ) const ;
	Fixed get_y(void ) const ;

};

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);
#endif