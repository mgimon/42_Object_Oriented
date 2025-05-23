#include "Form.hpp"

// *** MEMBER CLASSES *** //

class Form::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException: grade is too high!");
		}
};

class Form::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException: grade is too low!");
		}
};

// *** CANONICAL *** //

Form::Form() : _name(" "), _sgrade(150), _egrade(150), _signed(false) {
	std::cout << GRAY << "Creating a Form..." << RESET << std::endl;
}

Form::Form(const std::string &name, const int &sgrade, const int &egrade) : _name(name), _sgrade(sgrade), _egrade(egrade) {
	if (_sgrade < 1 || _egrade < 1) 
		throw GradeTooHighException();
	if (_sgrade > 150 || _egrade > 150) 
		throw GradeTooLowException();
	std::cout << GRAY << "Creating a Form..." << RESET << std::endl;
	this->_signed = false;
}

Form::Form(const Form &ref) : _name(ref._name), _sgrade(ref._sgrade), _egrade(ref._egrade) {
	std::cout << GRAY << "Copying a Form..." << RESET << std::endl;
	this->_signed = ref._signed;
}

Form& Form::operator = (const Form &ref) {
	if (this != &ref)
		this->_signed = ref._signed;
	std::cout << GRAY << "Assigning a Form..." << RESET << std::endl;
	return (*this);
}

Form::~Form() {
	std::cout << GRAY << "Destroying a Form..." << RESET << std::endl;
}

// *** OPERATORS *** //

std::ostream& operator<<(std::ostream& os, const Form &ref ) {
    os << ref.getName() << ", " << (ref.isSigned() ? "signed" : "unsigned") << " form sign grade " << ref.getSignGrade() << ", execute grade " << ref.getExecGrade();
    return os;
}

// *** METHODS *** //

const std::string	Form::getName() const {
	return (this->_name);
}

int	Form::getSignGrade() const {
	return (this->_sgrade);
}

int	Form::getExecGrade() const {
	return (this->_egrade);
}

bool Form::isSigned() const {
	return this->_signed;
}

void Form::beSigned(const Bureaucrat &ref) {
	if (this->getSignGrade() < ref.getGrade())
		throw (GradeTooLowException());
	else
		this->_signed = true;
}
