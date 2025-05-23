#ifndef INTERN_HPP
#define INTERN_HPP

#include <functional>
#include <map>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		
		class InternCantMakeFormException;

		Intern();
		Intern(const Intern &ref);
		Intern& operator = (const Intern &ref);
		~Intern();


		AForm* createShrubberyCreationForm(std::string target);
		AForm* createRobotomyRequestForm(std::string target);
		AForm* createPresidentialPardonForm(std::string target);

		AForm* makeForm(std::string name, std::string target);
};

#endif
