#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
: AForm(o), _target(o._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{
    if (this != &o) {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    const std::string filename = _target + "_shrubbery";
    std::ofstream out(filename.c_str());
    if (!out) {
        // Si tu subject no define excepción para esto, puedes lanzar std::runtime_error
        throw std::runtime_error("could not open output file");
    }

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