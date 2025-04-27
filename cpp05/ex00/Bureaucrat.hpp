#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <string>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[97m"

class Bureaucrat {

	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator = (const Bureaucrat& ref);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				setGrade(const int grade);
};

#endif
