#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

int main(void)
{
    Bureaucrat boss("Alice", 1);
    Bureaucrat mid("Charlie", 45);
    Intern intern;

    AForm *shrub; // empty pointer to Abstract
    AForm *robot; // empty pointer to Abstract
    AForm *pardon; // empty pointer to Abstract
    //AForm *iWillFail; // empty pointer to Abstract

    std::cout << std::endl << "--- Intern creates forms ---" << std::endl;
    shrub = intern.makeForm("shrubbery creation", "shrub");
    robot = intern.makeForm("robotomy request", "robot");
    pardon = intern.makeForm("presidential pardon", "pardon");
    //iWillFail = intern.makeForm("random name", "failure");

    std::cout << std::endl << "--- Trying to execute without signing ---" << std::endl;
    boss.executeForm(*shrub);
    mid.executeForm(*robot);
    boss.executeForm(*pardon);

    std::cout << std::endl << "--- Boss signs all forms ---" << std::endl;
    boss.signForm(*shrub);
    boss.signForm(*robot);
    boss.signForm(*pardon);

    std::cout << std::endl << "--- Executing forms with different bureaucrats ---" << std::endl;
    boss.executeForm(*shrub);     // should succeed
    mid.executeForm(*robot);      // should succeed unless mid bigger than 45
    mid.executeForm(*pardon);     // should fail unless mid grade smaller than 5
    boss.executeForm(*pardon);    // should succeed

    delete(shrub);
    delete(robot);
    delete(pardon);

    std::cout << std::endl;

    return (0);
}
