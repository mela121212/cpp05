#include "Bureaucrat.hpp"

static void testConstructorValid()
{
    std::cout << "\n=== testConstructorValid ===\n";
    Bureaucrat a("Alice", 1);
    Bureaucrat b("Bob", 150);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

static void testCopyAndAssign()
{
    std::cout << "\n=== testCopyAndAssign ===\n";

    Bureaucrat a("Original", 42);
    Bureaucrat copy(a); // constructor de copia
    std::cout << "a:    " << a << std::endl;
    std::cout << "copy: " << copy << std::endl;

    Bureaucrat b("OtherName", 100);
    std::cout << "Before assign b: " << b << std::endl;
    b = a; // operator=
    std::cout << "After assign b:  " << b << std::endl;

    std::cout << "(Nota) Si _name es const, tras b=a, el nombre de b suele quedarse como \"OtherName\".\n";
}

static void testConstructorInvalid()
{
    std::cout << "\n=== testConstructorInvalid ===\n";

    try
    {
        Bureaucrat x("TooHigh", 0);
        std::cout << x << std::endl; // no debería llegar aquí
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception (grade 0): " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat y("TooLow", 151);
        std::cout << y << std::endl; // no debería llegar aquí
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception (grade 151): " << e.what() << std::endl;
    }
}

static void testIncrementDecrement()
{
    std::cout << "\n=== testIncrementDecrement ===\n";

    Bureaucrat a("IncGuy", 2);
    std::cout << "Before increment: " << a << std::endl;
    a.incrementGrade(); // 2 -> 1
    std::cout << "After increment:  " << a << std::endl;

    Bureaucrat b("DecGuy", 149);
    std::cout << "Before decrement: " << b << std::endl;
    b.decrementGrade(); // 149 -> 150
    std::cout << "After decrement:  " << b << std::endl;
}

static void testIncrementTooFar()
{
    std::cout << "\n=== testIncrementTooFar ===\n";

    try
    {
        Bureaucrat a("Top", 1);
        std::cout << "Before increment: " << a << std::endl;
        a.incrementGrade(); // 1 -> 0 (debe lanzar)
        std::cout << "After increment:  " << a << std::endl; // no debería
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception (increment from 1): " << e.what() << std::endl;
    }
}

static void testDecrementTooFar()
{
    std::cout << "\n=== testDecrementTooFar ===\n";

    try
    {
        Bureaucrat a("Bottom", 150);
        std::cout << "Before decrement: " << a << std::endl;
        a.decrementGrade(); // 150 -> 151 (debe lanzar)
        std::cout << "After decrement:  " << a << std::endl; // no debería
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception (decrement from 150): " << e.what() << std::endl;
    }
}



int main()
{
    testConstructorValid();
    testConstructorInvalid();
    testCopyAndAssign();
    testIncrementDecrement();
    testIncrementTooFar();
    testDecrementTooFar();
    
    return 0;
}