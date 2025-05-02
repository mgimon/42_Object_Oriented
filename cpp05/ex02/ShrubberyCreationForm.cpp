#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    std::cout << GRAY << "Creating a ShrubberyCreationForm..." << RESET << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref) {
    std::cout << GRAY << "Copying a ShrubberyCreationForm..." << RESET << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &ref) {
    std::cout << GRAY << "Assigning a ShrubberyCreationForm..." << RESET << std::endl;
    AForm::operator=(ref);
    return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << GRAY << "Destroying a ShrubberyCreationForm..." << RESET << std::endl;
};



void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    try {
        if (!this->isSigned())
            throw(FormNotValidException());
        if (this->getExecGrade() < executor.getGrade())
            throw(GradeTooLowException());
        std::cout << GREEN << "Executing ShrubberyCreationForm " << this->getName() << RESET << std::endl;
    }
    catch (const FormNotValidException &e1) {
        std::cerr << RED << e1.what() << " form is not signed!" << RESET << std::endl;
    }
    catch (const GradeTooLowException &e2) {
        std::cerr << RED << e2.what() << " grade is too low to execute" << RESET << std::endl;
    }
};