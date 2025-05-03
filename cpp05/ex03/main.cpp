#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat  boss("Alice", 1);
    Bureaucrat  mid("Charlie", 50);
    Intern      intern;

    std::cout << std::endl << "--- Intern tries to create an invalid form ---" << std::endl;

    AForm* invalidForm = intern.makeForm("random invalid name", "InvalidForm");
    (void)invalidForm;

    std::cout << std::endl << "--- Intern tries to create valid forms ---" << std::endl;

    AForm* shrubForm = intern.makeForm("shrubbery creation", "ShrubForm");
    AForm* robotForm = intern.makeForm("robotomy request", "RobotForm");
    AForm* pardonForm = intern.makeForm("presidential pardon", "PardonForm");

    std::cout << std::endl << "--- Boss signs all forms ---" << std::endl;

    boss.signForm(*shrubForm);
    boss.signForm(*robotForm);
    boss.signForm(*pardonForm);

    std::cout << std::endl << "--- Executing forms with different bureaucrats ---" << std::endl;

    boss.executeForm(*shrubForm);    // should succeed
    mid.executeForm(*robotForm);     // should fail unless mid's grade <= 45
    mid.executeForm(*pardonForm);    // should fail unless mid's grade <= 5
    boss.executeForm(*pardonForm);   // should succeed

    std::cout << std::endl;

    delete shrubForm;
    delete robotForm;
    delete pardonForm;

    return 0;
}
