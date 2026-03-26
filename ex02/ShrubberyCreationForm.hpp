#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        explicit ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& o);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& o);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const& executor) const override;
};

#endif