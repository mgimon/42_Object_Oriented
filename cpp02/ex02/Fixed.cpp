
#include "Fixed.hpp"

/*-----------------------------------------CONSTRUCTORS----------------------------------------*/

Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	this->n = 0;
}

Fixed::Fixed(const int n) {
	//std::cout << "Int constructor called" << std::endl;
	this->n = n << f;
}

Fixed::Fixed(const float p) {
	//std::cout << "Float constructor called" << std::endl;
	this->n = (int)(roundf(p * (1 << f)));
}

Fixed::Fixed(const Fixed& ref) {
	//std::cout << "Copy constructor called" << std::endl;
	this->n = ref.n;
}

/*-----------------------------------------OPERATION OPERATORS----------------------------------------*/


Fixed& Fixed::operator=(const Fixed& ref) {
    if (this != &ref)
        this->n = ref.n;
    return *this;
}

// No protection needed
// toFloat used to operate correctly
// toFloat needs this& to be de-referenced

Fixed Fixed::operator+(const Fixed& ref) {
	Fixed tmp;

	tmp.setRawBits(this->n + ref.getRawBits());
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& ref) {
	Fixed tmp;

	tmp.setRawBits(this->n - ref.getRawBits());
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& ref) {
	Fixed tmp;

	tmp.setRawBits((int)((this->n * ref.getRawBits()) >> this->f));
    return (tmp);
}

Fixed Fixed::operator/(const Fixed& ref) {
	Fixed tmp;

	tmp.setRawBits((int)((this->n / ref.getRawBits()) << this->f));
    return (tmp);
}

/*-----------------------------------------INCREMENT OPERATORS-----------------------------------------*/

// Pre-increment (++x)
Fixed& Fixed::operator++() {
        ++n;
        return *this;
}

// Post-increment (x++): does increment on the object, but returns an un-incremented copy of it
Fixed Fixed::operator++(int) {
        Fixed tmp = *this;
		++n;
        return(tmp);
}

// Pre-decrement (++x)
Fixed& Fixed::operator--() {
        --n;
        return *this;
}

// Post-increment (x++): does decrement on the object, but returns an un-decremented copy of it
Fixed Fixed::operator--(int) {
        Fixed tmp = *this;
		--n;
        return(tmp);
}

/*-----------------------------------------COMPARISON OPERATORS----------------------------------------*/


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

/*-----------------------------------------OTHER-------------------------------------------------------*/

// Output stream - overloads '<<'
std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
    os << fixed.toFloat();
    return os;
}

// Destructor
Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

/*-----------------------------------------FUNCTIONS------------------------------------------------------*/

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

/*-----------------------------------------ADITIONAL FUNCTIONS----------------------------------------------*/


Fixed& Fixed::min(Fixed& object_a, Fixed& object_b) {
	if (object_a.n < object_b.n)
		return (object_a);
	else
		return (object_b);
}

const Fixed& Fixed::min(const Fixed& object_a, const Fixed& object_b) {
	if (object_a.n < object_b.n)
		return (object_a);
	else
		return (object_b);
}

Fixed& Fixed::max(Fixed& object_a, Fixed& object_b) {
	if (object_a.n > object_b.n)
		return (object_a);
	else
		return (object_b);
}

const Fixed& Fixed::max(const Fixed& object_a, const Fixed& object_b) {
	if (object_a.n > object_b.n)
		return (object_a);
	else
		return (object_b);
}
