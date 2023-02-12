#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"



int main()
{
    try
    {
		std::cout << "Formulaire 1"<< std::endl;
        Form f1("Formulaire 1", 50, 20);
        std::cout << f1 << std::endl;
        Bureaucrat b1("Bureaucrat 1", 20);
        std::cout << b1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
		std::cout <<"---------------------------"<< std::endl;
		std::cout <<"Formulaire 2"<< std::endl;
        Form f2("Formulaire 2", 10, 60);
        std::cout << f2 << std::endl;
        Bureaucrat b2("Bureaucrat 2", 30);
        std::cout << b2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
		std::cout <<"---------------------------"<< std::endl;
		std::cout <<"Formulaire 3"<< std::endl;
        Form f3("Formulaire 3", 200, 150);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
		std::cout <<"---------------------------"<< std::endl;
		std::cout <<"Formulaire 4"<< std::endl;
        Form f4("Formulaire 4", 20, 200);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}