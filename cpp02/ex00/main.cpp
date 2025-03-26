
#include "Fixed.hpp"

// My First Class in Orthodox Canonical Form

int	main(void)
{
	Fixed a; // constructor
	Fixed b( a ); // copy constructor;
	Fixed c;
	
	c = b; // c/a operator overload
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
