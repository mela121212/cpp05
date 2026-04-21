#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Bureaucrat boss("Boss", 1);
    Bureaucrat low("Intern", 150);

    ShrubberyCreationForm   s("Shrubb");
    RobotomyRequestForm     r("Robot");
    PresidentialPardonForm  p("Presi");

    std::cout << "\n--- Shrubbery ---\n";
    boss.executeForm(s);   // not signed -> fail
    low.signForm(s);       // too low -> fail (needs 145)
    boss.signForm(s);      // ok
    boss.executeForm(s);   // ok -> creates home_shrubbery

    std::cout << "\n--- Robotomy ---\n";
    boss.executeForm(r);   // not signed -> fail
    boss.signForm(r);      // ok
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << "Try " << i << ": ";
        boss.executeForm(r); // 50/50
    }

    std::cout << "\n--- Pardon ---\n";
    boss.executeForm(p);   // not signed -> fail
    boss.signForm(p);      // ok
    boss.executeForm(p);   // ok -> prints pardon

    return 0;
}