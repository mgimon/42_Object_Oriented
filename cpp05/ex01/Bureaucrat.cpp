#include "Bureaucrat.hpp"


// *** MEMBER CLASSES *** //

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException: ");
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooLowException: ");
		}
};


// *** CANONICAL *** //

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	try {
		if (_grade < 1) 
			throw GradeTooHighException();
		if (_grade > 150) 
			throw GradeTooLowException();
	}
	catch (const GradeTooHighException& e) {
		std::cerr << RED << e.what() << " bureaucrat grade must be within range!" << RESET << std::endl;
		exit(1);
	}
	catch (const GradeTooLowException& e) {
		std::cerr << RED << e.what() << " bureaucrat grade must be within range!" << RESET << std::endl;
		exit(1);
	}
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
	try
	{
		if (this->_grade <= 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch (const GradeTooHighException& e) {
		std::cerr << RED << e.what() << this->getName() << " already has the maximum grade!" << RESET << std::endl;
	}
}

void	Bureaucrat::decrementGrade() {
	try
	{
		if (this->_grade >= 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch (const GradeTooLowException& e) {
		std::cerr << RED << e.what() << this->getName() << " already has the minimum grade!" << RESET << std::endl;
	}
}

void	Bureaucrat::setGrade(const int grade) {
	this->_grade = grade;
}
