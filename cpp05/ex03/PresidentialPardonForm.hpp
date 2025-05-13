#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:

        class GradeTooHighException;
        class GradeTooLowException;
        class FormNotValidException;

        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &ref);
        PresidentialPardonForm& operator = (const PresidentialPardonForm &ref);
        ~PresidentialPardonForm();

        void    execute(Bureaucrat const &executor) const;
};

#endif
