#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy) : AForm(to_copy), _target(to_copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& to_copy)
{
    if (this != &to_copy)
    {
        AForm::operator=(to_copy);
        _target = to_copy._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "ShrubberyCreationForm: could not open output file";
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    const std::string filename = _target + "_shrubbery";
    std::ofstream out(filename.c_str());
    if (!out.is_open())
        throw FileOpenException();

    out <<
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n";
}

//TENGO QUE CONTROLAR EL FALLO DE OPEN FILE CON UNAS EXCEPTION??