#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== OK sign ===\n";
    Bureaucrat boss("Boss", 1);
    Form f1("TopSecret", 10, 10);
    std::cout << boss << std::endl;
    std::cout << f1 << std::endl;
    boss.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << "\n=== FAIL sign (grade too low) ===\n";
    Bureaucrat intern("Intern", 150);
    Form f2("Important", 100, 100);
    intern.signForm(f2);
    std::cout << f2 << std::endl;

    std::cout << "\n=== Invalid Form grades (constructor throws) ===\n";
    try
    {
        Form bad1("Bad", 0, 10);
    }
    catch (std::exception& e)
    { 
        std::cout << "bad1: " << e.what() << std::endl;
    }
    try 
    { 
        Form bad2("Bad", 10, 151); 
    }
    catch (std::exception& e) 
    { 
        std::cout << "bad2: " << e.what() << std::endl; 
    }

    return 0;
}