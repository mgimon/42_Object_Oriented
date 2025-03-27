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
		// copy overload
		Fixed& operator = (const Fixed& ref);
		// destructor
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

};

// '<<' overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
