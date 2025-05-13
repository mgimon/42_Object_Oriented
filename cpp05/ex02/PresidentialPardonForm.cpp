#include "PresidentialPardonForm.hpp"

class PresidentialPardonForm::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException ");
		}
};
class PresidentialPardonForm::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooLowException ");
		}
};
class PresidentialPardonForm::FormNotValidException : public std::exception {
	public:
		const char* what() const throw() {
			return ("FormNotValidException ");
		}
};

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
    std::cout << GRAY << "Creating a PresidentialPardonForm..." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
    std::cout << GRAY << "Creating a PresidentialPardonForm..." << RESET << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref) {
    std::cout << GRAY << "Copying a PresidentialPardonForm..." << RESET << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &ref) {
    std::cout << GRAY << "Assigning a PresidentialPardonForm..." << RESET << std::endl;
    AForm::operator=(ref);
    return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << GRAY << "Destroying a PresidentialPardonForm..." << RESET << std::endl;
};


void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->isSigned())
        throw(FormNotValidException());
    if (this->getExecGrade() < executor.getGrade())
        throw(GradeTooLowException());
    std::cout << YELLOW << "~ " << this->getName() << " has been pardoned by Zaphod Beeblebrox ~" << RESET << std::endl;
};
