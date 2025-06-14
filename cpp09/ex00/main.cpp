
#include "BitcoinExchange.hpp"


void	getcsv(std::ifstream& csvfile, BitcoinExchange& btcTool) {

	std::string	line;

	// get a line!
	while (std::getline(csvfile, line))
	{
		std::stringstream	ssline(line);
		std::string			key;
		std::string			value;

		// read until ',' and store in 'key'
		if (std::getline(ssline, key, ','))
		{
			// read the rest and store in 'value', if did read
			if (!std::getline(ssline, value))
				value = "";
		}
		// save, except cabeceras
		if (btcTool.isValidDateCsv(key))
			btcTool.feedMapRow(key, value);
	}

}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);

	std::ifstream		inputfile(argv[1]);
	std::ifstream		csvfile("data.csv");
	BitcoinExchange		btcTool;

	if (!inputfile)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	if (!csvfile)
		return (std::cerr << "Error: 'data.csv' file invalid or not found." << std::endl, 1);

	getcsv(csvfile, btcTool);
	btcTool.processInputFile(inputfile);

	csvfile.close();
	inputfile.close();

	return (0);
}
