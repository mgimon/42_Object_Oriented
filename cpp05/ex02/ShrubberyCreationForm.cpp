#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137) {
    std::cout << GRAY << "Creating a ShrubberyCreationForm..." << RESET << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) {
    std::cout << GRAY << "Copying a ShrubberyCreationForm..." << RESET << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &ref) {
    std::cout << GRAY << "Assigning a ShrubberyCreationForm..." << RESET << std::endl;
};