#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	//Bureaucrat b("Rob", 0);
	Bureaucrat	b0("Bobbert", 101);
	Bureaucrat	b1("Mr Robert", 1);
	Form		f0("miFormulario", 100, 100);
	//b0 = b1;
	std::cout << b0 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << f0 << std::endl;
	f0.beSigned(b0);
	std::cout << f0 << std::endl;
	//b1.incrementGrade();
	//b0.decrementGrade();
	//b1.setGrade(150);
	//b1.decrementGrade();
	return (0);
}
