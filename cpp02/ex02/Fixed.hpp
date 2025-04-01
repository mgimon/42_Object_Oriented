#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Fixed
{
	private:

		int					n;
		static const int	f = 8;

	public:

		// default constructor
		Fixed();
		// int constructor
		Fixed(const int n);
		// float constructor
		Fixed(const float p);
		// copy constructor
		Fixed(const Fixed& ref);

		// A/O overload ('=')
		Fixed& operator = (const Fixed& ref);
		// + overload ('+')
		Fixed operator + (const Fixed& ref);
		// - overload ('-')
		Fixed operator - (const Fixed& ref);
		// * overload ('*')
		Fixed operator * (const Fixed& ref);
		// / overload ('/')
		Fixed operator / (const Fixed& ref);

		// Pre increment overload
		Fixed& operator++();
		// Post increment overload
		Fixed operator++(int);
		// Pre decrement overload
		Fixed& operator--();
		// Post decrement overload
		Fixed operator--(int);

		// < overload
		bool operator<(const Fixed& ref) const;
		// > overload
		bool operator>(const Fixed& ref) const;
		// <= overload
		bool operator<=(const Fixed& ref) const;
		// >= overload
		bool operator>=(const Fixed& ref) const;
		// == overload
		bool operator==(const Fixed& ref) const;
		// != overload
		bool operator!=(const Fixed& ref) const;

		// destructor
		~Fixed();

		// Functions
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed& min(Fixed& object_a, Fixed& object_b);
		static const Fixed& min(const Fixed& object_a, const Fixed& object_b);
		static Fixed& max(Fixed& object_a, Fixed& object_b);
		static const Fixed& max(const Fixed& object_a, const Fixed& object_b);

};

// '<<' overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
