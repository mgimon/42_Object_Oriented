#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b0("God Himself", 0);
	Bureaucrat b1("Bobbert", 1);
	b1.incrementGrade();
	b1.setGrade(150);
	b1.decrementGrade();
	return (0);
}
