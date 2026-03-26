#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat 
{
    private:

        const std::string _name; //si es constante hay trampa en el operador copia
        int               _grade;

    public:

        Bureaucrat();
        Bureaucrat(const std::string& _name, int _grade);
        Bureaucrat(const Bureaucrat &to_copy);
        Bureaucrat &operator=(const Bureaucrat &to_copy);
        ~Bureaucrat();

        //getters
        const std::string& getName() const;
        int               getGrade() const;

        // operaciones
        void incrementGrade(); // subir "rango": baja (3 -> 2)
        void decrementGrade(); // bajar "rango": sube (3 -> 4)
        void signForm(Form& f);

        //clases anidadas
        class GradeTooHighException : public std::exception //hereda de exception el metodo what virtual
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif