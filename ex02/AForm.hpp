#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:

        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExecute;

    public:

        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &to_copy);
        AForm& operator=(const AForm &to_copy);
        virtual ~AForm();

        const std::string& getName() const;
        bool               getIsSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const& executor) const = 0; //abstracta

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif