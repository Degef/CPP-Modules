#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed(7.2f) + Fixed(2.7f) );
std::cout << b << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
