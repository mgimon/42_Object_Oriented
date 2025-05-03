#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[97m"

class AForm;

class Bureaucrat {

	private:

		const std::string	_name;
		int					_grade;

	public:

		class GradeTooHighException;
		class GradeTooLowException;

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator = (const Bureaucrat& ref);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				setGrade(const int grade);
		void				signForm(AForm &ref);
		void				executeForm(AForm const &ref) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& ref);

#endif
