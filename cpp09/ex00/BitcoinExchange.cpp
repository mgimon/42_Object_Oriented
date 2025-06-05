#include "BitcoinExchange.hpp"

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

void	BitcoinExchange::printDatabase() {

	std::map<std::string, float>::iterator it = this->database_.begin();
	std::cout << YELLOW << "Printing database..." << RESET << std::endl;
	while (it != this->database_.end())
	{
		std::cout << GREEN << it->first << RESET << " -> " << GRAY << std::fixed << std::setprecision(2) << it->second << RESET << std::endl;
		++it;
	}

}

void	BitcoinExchange::feedMapRow(std::string key, std::string value) {

	std::pair<std::string, float>	pair;

	pair = std::make_pair(key, std::atof(value.c_str()));
	this->database_.insert(pair);
}
