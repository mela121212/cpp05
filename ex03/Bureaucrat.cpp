#include "Bureaucrat.hpp"

static const int kHighestGrade = 1;
static const int kLowestGrade  = 150;

static void validateGrade(int grade)
{
    if (grade < kHighestGrade)
        throw Bureaucrat::GradeTooHighException();
    if (grade > kLowestGrade)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat() : _name("default") , _grade(kLowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) , _grade(grade)
{
    validateGrade(this->_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : _name(to_copy._name) , _grade(to_copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_copy)
{
    if (this != &to_copy)
    {
        // _name es const: NO se puede copiar asi que copiamos solo el grade
        validateGrade(to_copy._grade); //no hace falta del todo pero es mas seguro por si acso se añaden mas metodos que modifiquen grade
        this->_grade = to_copy._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

// ===== Getters =====

const std::string& Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

// ===== Operaciones =====

void Bureaucrat::incrementGrade()
{
    int newGrade = this->_grade - 1; // 3 -> 2
    validateGrade(newGrade);
    this->_grade = newGrade;
}

void Bureaucrat::decrementGrade()
{
    int newGrade = this->_grade + 1; // 3 -> 4
    validateGrade(newGrade);
    this->_grade = newGrade;
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->getName() << " couldn’t sign " << f.getName()
                  << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// ===== Exceptions what() =====

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

/*
En C++ un miembro const solo puede inicializarse al construir el objeto.
El constructor de copia crea un objeto nuevo, así que sí puede inicializar ese const con el valor del otro.
Si _name es const, no puedes modificarlo después de que el objeto exista.
Eso afecta sobre todo a operator= (asignación), porque operator= se usa sobre un objeto ya construido.
*/