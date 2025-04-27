#include "Bureaucrat.hpp"
#include "GeneralException.hpp"

// *** CANONICAL *** //

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	try
	{
		if (grade < 1 || grade > 150)
			throw GeneralException();
		else
			std::cout << GRAY << "Creating a Bureaucrat..." << RESET << std::endl;
	}
	catch (const GeneralException& e) {
		std::cerr << RED << e.what() << " this grade is invalid upon creation!" << RESET << std::endl;
	}
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

// *** METHODS *** //

const std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int					Bureaucrat::getGrade() const {
	return (this->_grade);
}

void				Bureaucrat::incrementGrade() {
	try
	{
		if (this->_grade <= 1)
			throw GeneralException();
		else
			this->_grade--;
	}
	catch (const GeneralException& e) {
		std::cerr << RED << e.what() << this->getName() << " already has the maximum grade!" << RESET << std::endl;
	}
}

void				Bureaucrat::decrementGrade() {
	try
	{
		if (this->_grade >= 150)
			throw GeneralException();
		else
			this->_grade++;
	}
	catch (const GeneralException& e) {
		std::cerr << RED << e.what() << this->getName() << " already has the minimum grade!" << RESET << std::endl;
	}
}

void				Bureaucrat::setGrade(const int grade) {
	this->_grade = grade;
}
