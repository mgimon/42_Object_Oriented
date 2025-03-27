
#include "Fixed.hpp"

/*
float n = 5.75
BINARIO = 101.11

NOTACION CIENTIFICA BINARIA (2^n x 1.n)
5.75 = 2^2 x 1.0111
----------------------------------------
S(+/-)   E-127(2^2)   (1.n -> parte decimal)
  1      10000001     01110000000000000000000
*/


// This program prints floats after converting them back from their useful fixed point integer version

int	main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	//std::cout << "But actually a is " << a.getRawBits() << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}
