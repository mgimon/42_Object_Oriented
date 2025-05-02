#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &ref);
        RobotomyRequestForm& operator = (const RobotomyRequestForm &ref);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const &executor) const;
};

#endif