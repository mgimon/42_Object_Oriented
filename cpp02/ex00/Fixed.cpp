
#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "Copy constructor called" << std::endl;
	this->n = ref.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "C/A operator overload function called" << std::endl;
    if (this != &ref)
        this->n = ref.getRawBits();
    return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->n;
}

void	Fixed::setRawBits(int const raw) {
	this->n = raw;
}
