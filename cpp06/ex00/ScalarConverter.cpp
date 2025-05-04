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

void		ScalarConverter::convert(std::string parameter) {
	if (parameter == "0")
	{
		std::cout << "char: " << 0 << std::endl;
		std::cout << "int: " << 0 << std::endl;
		std::cout << "float: " << "0.0f" << std::endl;
		std::cout << "double: " << "0.0" << std::endl;
	}
	else
	{
		std::cout << "char: " << parameter << std::endl;
		std::cout << "int: " << std::atoi(parameter.c_str()) << std::endl;
		std::cout << "float: " << static_cast<float>(std::atof(parameter.c_str())) << std::endl;
		std::cout << "double: " << std::atof(parameter.c_str()) << std::endl;
	}
}

/*
void convert(const std::string& parameter) {
    char *endptr;

    // Convertir a double primero (sirve para float también)
    errno = 0;
    double dValue = std::strtod(parameter.c_str(), &endptr);

    // Checkear si la conversión fue válida
    bool isValid = (errno == 0 && endptr != parameter.c_str());

    // CHAR
    if (!isValid || dValue < 0 || dValue > 127 || std::isnan(dValue))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(dValue) << "'" << std::endl;

    // INT
    if (!isValid || dValue < INT_MIN || dValue > INT_MAX || std::isnan(dValue))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(dValue) << std::endl;

    // FLOAT
    std::cout << "float: " << static_cast<float>(dValue);
    if (dValue == static_cast<int>(dValue))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;

    // DOUBLE
    std::cout << "double: " << dValue;
    if (dValue == static_cast<int>(dValue))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}
*/
