#include "Intern.hpp"

Intern::Intern() {
	std::cout << GRAY << "Creating an Intern..." << RESET << std::endl;
};

Intern::Intern(const Intern &ref) {
	(void)ref;
	std::cout << GRAY << "Copying an Intern..." << RESET << std::endl;
};

Intern& Intern::operator = (const Intern &ref) {
	(void)ref;
	std::cout << GRAY << "Assigning an Intern..." << RESET << std::endl;
	return (*this);
};

Intern::~Intern() {
	std::cout << GRAY << "Destroying an Intern..." << RESET << std::endl;
};


AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {

    std::map <std::string, AForm* (Intern::*)(std::string)> myMap;

    myMap["robotomy request"] = &Intern::createRobotomyRequestForm;
    myMap["shrubbery creation"] = &Intern::createShrubberyCreationForm;
    myMap["presidential pardon"] = &Intern::createPresidentialPardonForm;

    // (this->*mymap[name])(target);
    // =
    // &Intern::createRobotomyRequestForm(target);
    if (myMap.find(name) != myMap.end()) {
        return (this->*myMap[name])(target);
    }

    try {
        throw InternCantMakeFormException();
    }
    catch (const InternCantMakeFormException& e) {
        std::cerr << RED << "Intern can't make form!" << RESET << std::endl;
        return NULL;
    }
}
