#include "../includes/Intern.hpp"


Intern::Intern(){}

Intern::Intern(const Intern	&copy)
{
	*this = copy;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern& op)
{
	if (this != &op)
	{
		*this = op;
	}
	return(*this);
}

Form	*Intern::makeForm(std::string name, std::string target) const
{
	std::string types[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == types[i])
		{
			std::cout << "Intern creates " + types[i] + " form." << std::endl;
			switch (i)
			{
			case 0:
				return (new RobotomyRequestForm(name, target));
			case 1:
				return (new ShrubberyCreationForm(name, target));
			case 2:
				return (new PresidentialPardonForm(name, target));
			}	
		}
	}
	std::cout << "No forms were found. Please go to the reception desk" << std::endl;
	return NULL;
}