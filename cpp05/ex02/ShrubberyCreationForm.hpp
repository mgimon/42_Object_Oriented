#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
        
        public:

        class GradeTooHighException;
        class GradeTooLowException;
        class FormNotValidException;

        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &ref);
        ShrubberyCreationForm& operator = (const ShrubberyCreationForm &ref);
        ~ShrubberyCreationForm();

        void    execute(Bureaucrat const &executor) const;
};

#endif
