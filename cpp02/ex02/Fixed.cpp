
#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->n = 0;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->n = n << f;
}

Fixed::Fixed(const float p) {
	std::cout << "Float constructor called" << std::endl;
	this->n = (int)(roundf(p * (1 << f)));
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "Copy constructor called" << std::endl;
	this->n = ref.n;
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ref)
        this->n = ref.n;
    return *this;
}

bool Fixed::operator<(const Fixed& ref) const {
	return this->n < ref.n;
}

bool Fixed::operator>(const Fixed& ref) const {
	return this->n > ref.n;
}

bool Fixed::operator<=(const Fixed& ref) const {
	return this->n <= ref.n;
}

bool Fixed::operator>=(const Fixed& ref) const {
	return this->n >= ref.n;
}

bool Fixed::operator==(const Fixed& ref) const {
	return this->n == ref.n;
}

bool Fixed::operator!=(const Fixed& ref) const {
	return this->n != ref.n;
}

// overloads '<<'
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const {
	return this->n;
}

void	Fixed::setRawBits(int const raw) {
	this->n = raw;
}

// 1 << 8 equals 2^8 in bit operations
float	Fixed::toFloat() const {
	return ((float)n / (1 << f));
}

int		Fixed::toInt() const {
	return (n >> f);
}
