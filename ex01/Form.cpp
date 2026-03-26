#include "Form.hpp"

static const int kHighestGrade = 1;
static const int kLowestGrade  = 150;

static void validateGrade(int grade)
{
    if (grade < kHighestGrade)
        throw Form::GradeTooHighException();
    if (grade > kLowestGrade)
        throw Form::GradeTooLowException();
}

Form::Form() : _name("default") , _isSigned(false) , _gradeToSign(kLowestGrade) , _gradeToExecute(kLowestGrade)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    validateGrade(_gradeToSign);
    validateGrade(_gradeToExecute);
}

Form::Form(const Form& other) : _name(other._name) , _isSigned(other._isSigned) , _gradeToSign(other._gradeToSign) , _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // const members cannot be reassigned (_name, _gradeToSign, _gradeToExecute)
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& b)
{
    // Bureaucrat grade must be <= required grade
    if (b.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form \"" << f.getName() << "\""
       << " [signed: " << (f.getIsSigned() ? "true" : "false")
       << ", gradeToSign: " << f.getGradeToSign()
       << ", gradeToExecute: " << f.getGradeToExecute()
       << "]";
    return os;
}