#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed(2) / Fixed(1) << std::endl;
	std::cout << Fixed(2) / Fixed(0.5f) << std::endl;
	std::cout << Fixed(2) * Fixed(0.75f) << std::endl;
	std::cout << Fixed(2) * Fixed(2) << std::endl;
return 0;
}
