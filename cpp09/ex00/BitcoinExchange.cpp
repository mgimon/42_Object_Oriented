#include "BitcoinExchange.hpp"

// ** CANONICAL ** //

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) : database_(ref.database_) {}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &ref) {
	if (this != &ref)
	{
		this->database_ = ref.database_;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// ** UTILS ** //

void	BitcoinExchange::printBadInput(std::string input) { std::cout << "Error: bad input => " << input << std::endl; }

bool	BitcoinExchange::isValidDateCsv(std::string str)
{
	char	c;
	int		i = 0;
	while (str[i])
	{
		c = str[i];
		if (!std::isdigit(static_cast<unsigned char>(c)) && c != '-')
			return (false);
		i++;
	}
	return (true);
}

bool	BitcoinExchange::isValidDate(std::string str) {
	// year is not checked, can be any
	int	month;
	int	day;

	if (!isValidDateCsv(str))
		return (false);
	if (str.length() != 10)
		return (false);
	if (str[4] != '-' || str[7] != '-')
		return (false);
	char	c;
	int		i = 0;
	while (str[i])
	{
		c = str[i];
		if (i != 4 && i != 7) // must be digit, 4 and 7 are '-'
		{
			if (!std::isdigit(static_cast<unsigned char>(c)))
				return (false);
		}
		i++;
	}

	month = atoi(str.substr(5, 2).c_str());
	day = atoi(str.substr(8, 2).c_str());

	if (day > 31 || month > 12)
		return (false);

	return (true);
}

bool BitcoinExchange::isNum(const std::string& line) {
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (std::isalpha(static_cast<unsigned char>(line[i])))
			return (false);
	}
	return (true);
}

void	BitcoinExchange::printDatabase() {

	std::map<std::string, float>::iterator it = this->database_.begin();
	std::cout << YELLOW << "Printing database..." << RESET << std::endl;
	while (it != this->database_.end())
	{
		std::cout << GREEN << it->first << RESET << " -> " << GRAY << std::fixed << std::setprecision(2) << it->second << RESET << std::endl;
		++it;
	}

}

// ** FUNCTIONS ** //

void	BitcoinExchange::feedMapRow(std::string key, std::string value) {

	std::pair<std::string, float>	pair;

	pair = std::make_pair(key, std::atof(value.c_str()));
	this->database_.insert(pair);
}

void	BitcoinExchange::processInputFile(std::ifstream& inputfile) {

	std::string	line;
	std::string	date;
	std::map<std::string, float>::iterator it;

	if (this->database_.empty())
		return ;
	while (std::getline(inputfile, line))
	{
		std::string			key;
		std::string			value;
		it = this->database_.begin();

		if (line.length() >= 10 && isNum(line))
		{
			value = "";
			key = line.substr(0, 10);
			if (line.length() >= 14)
				value = line.substr(13);
			if (!isValidDate(key))
				std::cout << "Error: bad input => " << key << std::endl;

			if (!key.empty())
			{

					while (it != this->database_.end() && it->first <= key)
						++it;
					if (it != this->database_.begin())
						--it;
					long lvalue = static_cast<long>(atol(value.c_str()));
					if (lvalue > INT_MAX)
						std::cout << "Error: too large a number" << std::endl;
					else if (lvalue < 0)
						std::cout << "Error: not a positive number" << std::endl;
					else
					{
						if (!value.empty())
							std::cout << it->first << " => " << value << " = " << static_cast<float>(atof(value.c_str())) * it->second << std::endl;
					}
			}
		}
	}
}


