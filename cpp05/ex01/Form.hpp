#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[97m"

class Bureaucrat;

class Form {

	private:

		const std::string	_name;
		const int			_sgrade;
		const int			_egrade;
		bool				_signed;

	public:

		class GradeTooHighException;
		class GradeTooLowException;

		Form();
		Form(const std::string &name, const int &sgrade, const int &egrade);
		Form(const Form &ref);
		Form& operator = (const Form &ref);
		~Form();

		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool 				isSigned() const;
		void				beSigned(const Bureaucrat &ref);

};

std::ostream &operator<<(std::ostream &os, const Form &ref);

#endif
