#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

class ScalarConverter {

	private:

		ScalarConverter();

	public:

		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter& operator = (const ScalarConverter &ref);
		~ScalarConverter();

		static void		convert(std::string parameter);
};


#endif
