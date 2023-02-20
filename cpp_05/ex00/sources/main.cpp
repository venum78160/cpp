#include "../includes/Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat bureaucrat1("John", 1);
        std::cout << bureaucrat1 << std::endl;

        bureaucrat1.increment();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "...After John" << std::endl;
    try
    {
        Bureaucrat bureaucrat2("Yoshi", 150);
        std::cout << bureaucrat2 << std::endl;

        bureaucrat2.decrement();
        std::cout << bureaucrat2 << std::endl;

        bureaucrat2.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "...After Yoshi" << std::endl;
    try
    {
        Bureaucrat bureaucrat3("Val", 160);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "...After Val" << std::endl;
    try
    {
        Bureaucrat bureaucrat4("Imen", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << "...After Imen" << std::endl;

    return 0;
}