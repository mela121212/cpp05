#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {};

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy) : AForm(to_copy), _target(to_copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &to_copy) 
{
    if (this != &to_copy)
    {
        AForm::operator=(to_copy);
        _target = to_copy._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
