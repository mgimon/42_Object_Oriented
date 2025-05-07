#include "Bureaucrat.hpp"


// *** MEMBER CLASSES *** //

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException: grade is too high!");
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException: grade is too low!");
		}
};


// *** CANONICAL *** //

Bureaucrat::Bureaucrat() : _name(" "), _grade(150) {
	std::cout << GRAY << "Creating a Bureaucrat..." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) 
		throw GradeTooHighException();
	if (_grade > 150) 
		throw GradeTooLowException();
	std::cout << GRAY << "Creating a Bureaucrat..." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name), _grade(ref._grade) { 	std::cout << GRAY << "Copying a Bureaucrat..." << RESET << std::endl; }

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& ref) {
	if (this != &ref) {
		_grade = ref._grade;
	}
	std::cout << GRAY << "Assigning a Bureaucrat..." << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << GRAY << "Destroying a Bureaucrat..." << RESET << std::endl; }



// *** OPERATORS *** //

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref ) {
    os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
    return os;
}



// *** METHODS *** //

const std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int					Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::setGrade(const int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::signForm(Form &ref) {
	try {
		ref.beSigned(*this);
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << RED << e.what() << " - couldn't sign form!" << RESET << std::endl;
	}
	std::cout << GREEN << this->getName() << " signed " << ref.getName() << RESET << std::endl;
		
}
