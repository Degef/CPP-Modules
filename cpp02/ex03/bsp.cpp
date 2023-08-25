#include "Point.hpp"

static Fixed   abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

Fixed calculateTriangleArea(const Point& p1, const Point& p2, const Point& p3) {
    Fixed term1 = p1.get_x() * (p2.get_y() - p3.get_y());
    Fixed term2 = p2.get_x() * (p3.get_y() - p1.get_y());
    Fixed term3 = p3.get_x() * (p1.get_y() - p2.get_y());

    Fixed area = (term1 + term2 + term3) / 2;

    return area;
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
    Fixed A1 = abs(calculateTriangleArea(point, a, b));
    Fixed A2 = abs(calculateTriangleArea(point, b, c));
    Fixed A3 = abs(calculateTriangleArea(point, c, a));

	Fixed TA = abs(calculateTriangleArea(a, b, c));
    return (TA == A1 + A2 + A3);
}
