// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    static AForm* makeShrubbery(const std::string& target);
    static AForm* makeRobotomy(const std::string& target);
    static AForm* makePardon(const std::string& target);
};

#endif