#include "CopyMaker.hpp"

int main()
{
	std::string 	filename = "test";
	std::string		new_filename = filename + ".replace";
	std::string		line;

    std::ifstream	file(filename.c_str());

	if (!file) 
		return (std::cerr << "Error opening file" << std::endl, 1);

	std::ofstream	newfile(new_filename.c_str());

	if (!newfile)
		return (std::cerr << "Error creating newfile" << std::endl, 1);

	// Copiar línea por línea
	while (std::getline(file, line))
		newfile << line << std::endl;

	file.close();  // Cerrar el archivo
	newfile.close();

	return 0;
}
