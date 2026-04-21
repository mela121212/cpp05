#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    struct FormEntry
    {
        const char* name;
        AForm* (*creator)(const std::string& target);
    };
    static const FormEntry forms[] =
    {
        { "shrubbery creation", &Intern::makeShrubbery },
        { "robotomy request", &Intern::makeRobotomy },
        { "presidential pardon", &Intern::makePardon }
    };
    for (size_t i = 0; i < 3; ++i)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }
    std::cout << "Intern error: unknown form name \"" << formName << "\"" << std::endl;
    return 0;
}