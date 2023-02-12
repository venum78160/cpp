#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
  try
  {
    Bureaucrat b("b", 60);
    ShrubberyCreationForm s("shrubbery", "test");
    RobotomyRequestForm r("robotomy", "Palmi");
    PresidentialPardonForm p("pardon", "Palmi");

    b.signForm(s);
    std::cout << s << std::endl;
    b.executeForm(s);

    b.signForm(r);
    std::cout << r << std::endl;
    b.executeForm(r);

    b.signForm(p);
    std::cout << p << std::endl;
    b.executeForm(p);
	std::cout << "End Try" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}