#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:

        class GradeTooHighException;
        class GradeTooLowException;
        class FormNotValidException;

        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &ref);
        RobotomyRequestForm& operator = (const RobotomyRequestForm &ref);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const &executor) const;
};

#endif
