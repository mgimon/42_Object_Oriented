#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
	//Bureaucrat b("Rob", 0);
	Bureaucrat	b0("Bobbert", 100);
	Bureaucrat	b1("Mr Robert", 1);
	Form		f0("miFormulario", 100, 100);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << b0 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << f0 << std::endl;
	b0.signForm(f0);
	std::cout << f0 << std::endl;
	b1.signForm(f0);
	std::cout << f0 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	//b1.incrementGrade();
	//b0.decrementGrade();
	//b1.setGrade(150);
	//b1.decrementGrade();
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}
