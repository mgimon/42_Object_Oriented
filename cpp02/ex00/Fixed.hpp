#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Fixed
{
	private:

		int					n;
		static const int	f = 8;

	public:

		// default constructor
		Fixed();
		// copy constructor
		Fixed(const Fixed& ref);
		// copy overload
		Fixed& operator = (const Fixed& ref);
		// destructor
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

};

#endif
