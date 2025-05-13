#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooHighException ");
		}
};
class AForm::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("GradeTooLowException ");
		}
};
class AForm::FormNotValidException : public std::exception {
	public:
		const char* what() const throw() {
			return ("FormNotValidException ");
		}
};

// *** CANONICAL *** //

AForm::AForm() : _name(" "), _sgrade(150), _egrade(150), _signed(false) {
	std::cout << GRAY << "Creating a AForm..." << RESET << std::endl;
}

AForm::AForm(const std::string &name, const int &sgrade, const int &egrade) : _name(name), _sgrade(sgrade), _egrade(egrade) {
	if (_sgrade < 1 || _egrade < 1) 
		throw GradeTooHighException();
	if (_sgrade > 150 || _egrade > 150) 
		throw GradeTooLowException();
	std::cout << GRAY << "Creating a AForm..." << RESET << std::endl;
	this->_signed = false;
}

AForm::AForm(const AForm &ref) : _name(ref._name), _sgrade(ref._sgrade), _egrade(ref._egrade) {
	std::cout << GRAY << "Copying a AForm..." << RESET << std::endl;
	this->_signed = ref._signed;
}

AForm& AForm::operator = (const AForm &ref) {
	if (this != &ref)
		this->_signed = ref._signed;
	std::cout << GRAY << "Assigning a AForm..." << RESET << std::endl;
	return (*this);
}

AForm::~AForm() {
	std::cout << GRAY << "Destroying a AForm..." << RESET << std::endl;
}

// *** OPERATORS *** //

std::ostream& operator<<(std::ostream& os, const AForm &ref ) {
    os << ref.getName() << ", " << (ref.isSigned() ? "signed" : "unsigned") << " form sign grade " << ref.getSignGrade() << ", execute grade " << ref.getExecGrade();
    return os;
}

// *** METHODS *** //

const std::string	AForm::getName() const {
	return (this->_name);
}

int	AForm::getSignGrade() const {
	return (this->_sgrade);
}

int	AForm::getExecGrade() const {
	return (this->_egrade);
}

bool AForm::isSigned() const {
	return this->_signed;
}

void AForm::beSigned(const Bureaucrat &ref) {
	if (this->getSignGrade() < ref.getGrade())
		throw (GradeTooLowException());
	else
		this->_signed = true;
}