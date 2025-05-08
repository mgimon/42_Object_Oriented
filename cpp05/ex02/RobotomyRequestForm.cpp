#include "RobotomyRequestForm.hpp"

class RobotomyRequestForm::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException: ");
		}
};
class RobotomyRequestForm::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooLowException: ");
		}
};
class RobotomyRequestForm::FormNotValidException : public std::exception {
	public:
		const char* what() const throw() {
			return ("FormNotValidException: ");
		}
};

RobotomyRequestForm::RobotomyRequestForm() : AForm() {
    std::cout << GRAY << "Creating a RobotomyRequestForm..." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
    std::cout << GRAY << "Creating a RobotomyRequestForm..." << RESET << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref) {
    std::cout << GRAY << "Copying a RobotomyRequestForm..." << RESET << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &ref) {
    std::cout << GRAY << "Assigning a RobotomyRequestForm..." << RESET << std::endl;
    AForm::operator=(ref);
    return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << GRAY << "Destroying a RobotomyRequestForm..." << RESET << std::endl;
};



void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
        if (!this->isSigned())
            throw(FormNotValidException());
        if (this->getExecGrade() < executor.getGrade())
            throw(GradeTooLowException());
        std::cout << YELLOW << "~ Beep beep bop boop... ";
        srand(time(NULL));
        if (rand() % 2 == 0)
            std::cout << this->getName() << " has been robotomized ~" << RESET << std::endl;
        else
            std::cout << "Robotomization has failed ~" << RESET << std::endl;
};
