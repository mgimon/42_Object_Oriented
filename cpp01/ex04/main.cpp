#include <iostream>
#include <fstream>
#include <string>

static std::string	change_line(std::string line, std::string s1, std::string s2)
{
    std::string result;
    size_t pos = 0;
    size_t last_pos = 0;

    // While s1 appears in line
    while ((last_pos = line.find(s1, pos)) != std::string::npos)
    {
        // Add before s1
        result.append(line.substr(pos, last_pos - pos));

        // Add s2 instead of s1
        result.append(s2);

        // Move pos beyond s1
        pos = last_pos + s1.length();
    }

    // Add after last s1 (or from 0 if no s1)
    result.append(line.substr(pos));
    return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << "Please, execute with three arguments" << std::endl, 1);

	std::string 	filename = argv[1];
	std::string		new_filename = filename + ".replace";
	std::string		line;
    std::ifstream	file(filename.c_str());

	if (!file) 
		return (std::cerr << "Error opening file" << std::endl, 1);

	std::ofstream	newfile(new_filename.c_str());
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	if (!newfile)
		return (std::cerr << "Error creating newfile" << std::endl, 1);

	while (std::getline(file, line))
	{
		line = change_line(line, s1, s2);
		newfile << line << std::endl;
	}

	file.close();
	newfile.close();
	return (0);
}
