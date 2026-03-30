#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm &to_copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& to_copy);
        virtual ~RobotomyRequestForm();

        void execute(Bureaucrat const& executor) const;
        const std::string& getTarget() const;

    private:
        std::string _target;
};

#endif