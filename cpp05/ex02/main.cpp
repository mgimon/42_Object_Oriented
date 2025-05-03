#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat boss("Alice", 1);
    Bureaucrat intern("Bob", 150);
    Bureaucrat mid("Charlie", 50);

    ShrubberyCreationForm shrub("ShrubForm");
    RobotomyRequestForm robot("RobotForm");
    PresidentialPardonForm pardon("PardonForm");

    std::cout << std::endl << "--- Trying to execute without signing ---" << std::endl;
    boss.executeForm(shrub);
    mid.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << std::endl << "--- Intern tries to sign forms (should fail) ---" << std::endl;
    intern.signForm(shrub);
    intern.signForm(robot);
    intern.signForm(pardon);

    std::cout << std::endl << "--- Boss signs all forms ---" << std::endl;
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << std::endl << "--- Executing forms with different bureaucrats ---" << std::endl;
    boss.executeForm(shrub);     // should succeed
    mid.executeForm(robot);      // should fail unless mid grade <= 45
    mid.executeForm(pardon);     // should fail unless mid grade <= 5
    boss.executeForm(pardon);    // should succeed

    std::cout << std::endl;

    return 0;
}
