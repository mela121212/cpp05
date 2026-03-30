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
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &to_copy);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const& executor) const;

        class FileOpenException : public std::exception 
        {
            public:
                const char* what() const throw();
        };
};

#endif