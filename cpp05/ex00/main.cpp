#include "Bureaucrat.hpp"

int main(void)
{
	
	try {
		//Bureaucrat b("Rob", 0);
        Bureaucrat b0("Bobbert", 150);
        Bureaucrat b1("Mr Robert", 1);
        b0 = b1;
        std::cout << b0 << std::endl;
        std::cout << b1 << std::endl;
		b1.incrementGrade();
		b0.decrementGrade();
		b1.setGrade(150);
		b1.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
	return (0);
}
