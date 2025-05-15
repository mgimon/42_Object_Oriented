#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << GRAY << "Creating a converter..." << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) {
	*this = ref;
	std::cout << GRAY << "Copying a converter..." << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter &ref) {
	if (this != &ref)
		*this = ref;
	return (*this);
	std::cout << GRAY << "Assigning a converter..." << RESET << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << GRAY << "Destroying a converter..." << RESET << std::endl;
}

// TODO : inff, -inff, etc

bool is_nan(double x) {
    return x != x;
}

void print_char(bool isValid, double number) {

    std::cout << "char: ";

    if ((number >= 0 && number <= 31) || number == 127)
        std::cout << "Non displayable" << std::endl;

    else if (!isValid || is_nan(number) || number > 127)
        std::cout << "impossible" << std::endl;

    else
        std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
}

void print_int(bool isValid, double number) {

    if (!isValid || number < INT_MIN || number > INT_MAX || is_nan(number))
        std::cout << "int: impossible" << std::endl;

    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;
}

void ScalarConverter::convert(std::string parameter) {
    
    errno       = 0;
    char        *endptr;

    const char  *str = parameter.c_str();
    double      number = std::strtod(str, &endptr);
    bool        isValid = (errno == 0 && endptr != str);

    print_char(isValid, number);
    print_int(isValid, number);


    double  intpart;
    bool    isInteger = (std::modf(number, &intpart) == 0);


    // number is always valid since it's already a double. this is just printing style:
    std::cout << "float: " << std::fixed << std::setprecision(isInteger? 1 : 4) << static_cast<float>(number) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(isInteger? 1 : 4) << number << std::endl;
}

