#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime> 
#include <sstream>
#include <limits>
#include <algorithm>
#include <map>
#include <fstream>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

class BitcoinExchange {

	private:

		std::map<std::string, float>	database_;
		std::map<std::string, std::string>	input_;

	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange& operator = (const BitcoinExchange &ref);
		~BitcoinExchange();

		void	printDatabase();
		void	printBadInput(std::string input);
		bool	isValidDateCsv(std::string str);
		bool	isValidDate(std::string str);

		void	feedMapRow(std::string key, std::string value);
		void	feedInputRow(std::string key, std::string value);

		void	processInputLine(std::string key, std::string value);
		void	processInputLineByLine();
		

};


#endif
