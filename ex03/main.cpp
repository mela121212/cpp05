#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n--- shrubbery creation ---\n";
    if (AForm* f = intern.makeForm("shrubbery creation", "home"))
    {
        boss.signForm(*f);
        boss.executeForm(*f);
        delete f;
    }

    std::cout << "\n--- robotomy request ---\n";
    if (AForm* f = intern.makeForm("robotomy request", "Bender"))
    {
        boss.signForm(*f);
        for (int i = 0; i < 10; ++i)
            boss.executeForm(*f);
        delete f;
    }

    std::cout << "\n--- presidential pardon ---\n";
    if (AForm* f = intern.makeForm("presidential pardon", "Arthur Dent"))
    {
        boss.signForm(*f);
        boss.executeForm(*f);
        delete f;
    }

    return 0;
}