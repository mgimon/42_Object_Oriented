#include "PresidentialPardonForm.hpp"

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




int PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    try {
        if (!this->isSigned())
            throw(FormNotValidException());
        if (this->getExecGrade() < executor.getGrade())
            throw(GradeTooLowException());
        std::cout << YELLOW << "~ " << this->getName() << " has been pardoned by Zaphod Beeblebrox ~" << RESET << std::endl;
        return (0);
    }
    catch (const FormNotValidException &e1) {
        std::cerr << RED << e1.what() << " form is not signed!" << RESET << std::endl;
        return (1);
    }
    catch (const GradeTooLowException &e2) {
        std::cerr << RED << e2.what() << " grade is too low to execute" << RESET << std::endl;
        return (1);
    }
};
