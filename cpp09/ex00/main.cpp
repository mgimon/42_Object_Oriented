
#include "BitcoinExchange.hpp"

bool	isValidDate(std::string str)
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

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);

	std::ifstream		inputfile(argv[1]);
	std::ifstream		csvfile("data.csv");
	std::string			line;
	BitcoinExchange		btcTool;

	if (!inputfile)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	if (!csvfile)
		return (std::cerr << "Error: 'data.csv' file invalid or not found." << std::endl, 1);

	while (std::getline(csvfile, line))
	{
		std::stringstream	ssline(line);
		std::string			key;
		std::string			value;

		if (std::getline(ssline, key, ','))
		{
			if (!std::getline(ssline, value))
				value = "";
		}
		if (isValidDate(key))
			btcTool.feedMapRow(key, value);
	}

	csvfile.close();
	inputfile.close();

	btcTool.printDatabase();

	return (0);
}
