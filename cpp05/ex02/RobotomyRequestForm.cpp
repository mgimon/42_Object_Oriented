#include "RobotomyRequestForm.hpp"

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
    try {
        if (!this->isSigned())
            throw(FormNotValidException());
        if (this->getExecGrade() < executor.getGrade())
            throw(GradeTooLowException());
        std::cout << GREEN << "Executing RobotomyRequestForm " << this->getName() << RESET << std::endl;
    }
    catch (const FormNotValidException &e1) {
        std::cerr << RED << e1.what() << " form is not signed!" << RESET << std::endl;
    }
    catch (const GradeTooLowException &e2) {
        std::cerr << RED << e2.what() << " grade is too low to execute" << RESET << std::endl;
    }
};