#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    // 1) Ejecutar sin firmar (debe fallar: NotSignedException)
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm f("Arthur Dent");

        std::cout << "\n[CASE 1] execute without signing\n";
        boss.executeForm(f);
    }

    // 2) Firmar con grade demasiado bajo (necesita <= 25)
    {
        Bureaucrat low("Low", 150);
        PresidentialPardonForm f("Ford Prefect");

        std::cout << "\n[CASE 2] sign with low grade\n";
        low.signForm(f);
    }

    // 3) Firmar OK pero ejecutar con grade demasiado bajo (exec necesita <= 5)
    {
        Bureaucrat signer("Signer", 25);   // puede firmar
        Bureaucrat execLow("ExecLow", 6);  // NO puede ejecutar (6 > 5)
        PresidentialPardonForm f("Trillian");

        std::cout << "\n[CASE 3] sign OK, execute with insufficient grade\n";
        signer.signForm(f);
        execLow.executeForm(f);            // debe fallar GradeTooLowException
    }

    // 4) Firmar y ejecutar OK
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm f("Marvin");

        std::cout << "\n[CASE 4] sign and execute OK\n";
        boss.signForm(f);
        boss.executeForm(f);               // imprime el pardon
    }

    return 0;
}