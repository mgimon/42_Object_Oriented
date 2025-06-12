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
	int	year;
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
	year = atoi(str.substr(0, 4).c_str());
	month = atoi(str.substr(5, 2).c_str());
	day = atoi(str.substr(8, 2).c_str());

	if (day > 31 || month > 12)
		return (false);

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

void	BitcoinExchange::feedInputRow(std::string key, std::string value) {

	std::pair<std::string, std::string>	pair;

	pair = std::make_pair(key, value);
	this->input_.insert(pair);
}

void	BitcoinExchange::processInputLineByLine() {
	std::map<std::string, std::string>::iterator it = this->input_.begin();

	while (it != this->input_.end())
	{
		this->processInputLine(it->first, it->second);
		++it;
	}
}

void	BitcoinExchange::processInputLine(std::string key, std::string value) {

	if (key.empty() || !isValidDate(key))
		printBadInput(key);
	// check negativo
	// check maxint
}
