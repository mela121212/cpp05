#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const int kHighestGrade = 1;
static const int kLowestGrade  = 150;

static void validateGrade(int grade)
{
    if (grade < kHighestGrade)
        throw AForm::GradeTooHighException();
    if (grade > kLowestGrade)
        throw AForm::GradeTooLowException();
}

AForm::AForm() : _name("default") , _isSigned(false) , _gradeToSign(kLowestGrade) , _gradeToExecute(kLowestGrade)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    validateGrade(_gradeToSign);
    validateGrade(_gradeToExecute);
}

AForm::AForm(const AForm& other) : _name(other._name) , _isSigned(other._isSigned) , _gradeToSign(other._gradeToSign) , _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // const members cannot be reassigned
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const 
{ 
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{ 
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{ 
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm \"" << f.getName() << "\""
       << " [signed: " << (f.getIsSigned() ? "true" : "false")
       << ", gradeToSign: " << f.getGradeToSign()
       << ", gradeToExecute: " << f.getGradeToExecute()
       << "]";
    return os;
}