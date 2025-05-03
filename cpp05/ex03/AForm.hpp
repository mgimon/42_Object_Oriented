#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
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

class AForm {

	private:

		const std::string	_name;
		const int			_sgrade;
		const int			_egrade;
		bool				_signed;

	public:

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return ("GradeTooHighException: ");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return ("GradeTooLowException: ");
				}
		};
		class FormNotValidException : public std::exception {
			public:
				const char* what() const throw() {
					return ("FormNotValidException: ");
				}
		};

		AForm(const std::string &name, const int &sgrade, const int &egrade);
		AForm(const AForm &ref);
		AForm& operator = (const AForm &ref);
		virtual ~AForm();

		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool 				isSigned() const;
		int					beSigned(const Bureaucrat &ref);

		virtual	int		execute(const Bureaucrat &ref) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &ref);

#endif
