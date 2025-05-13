#include "ShrubberyCreationForm.hpp"


class ShrubberyCreationForm::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException ");
		}
};
class ShrubberyCreationForm::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooLowException ");
		}
};
class ShrubberyCreationForm::FormNotValidException : public std::exception {
	public:
		const char* what() const throw() {
			return ("FormNotValidException ");
		}
};

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
    std::cout << GRAY << "Creating a ShrubberyCreationForm..." << RESET << std::endl;
}

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
    
    std::string tree =
    "   /\\\n"
    "  /  \\\n"
    " /____\\\n"
    "   ||\n";
    

    if (!this->isSigned())
        throw(FormNotValidException());
    if (this->getExecGrade() < executor.getGrade())
        throw(GradeTooLowException());
        
    std::cout << YELLOW << "~ A file was created ~" << RESET << std::endl;
    std::ofstream file((this->getName() + "_shrubbery").c_str());
    for (int i = 0; i < 5; ++i)
        file << tree << "\n";
    file.close();
};
