#include "../includes/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : Form("Unknown", 72, 45), _target("Anywhere"){}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target) : Form(name, 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm	&copy) : Form(copy){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& op)
{
	if (this != &op)
	{
		Form::operator=(op);
	}
	return(*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	makeit();
}

void	RobotomyRequestForm::makeit(void) const
{
	srand((unsigned int)time(NULL));
	int random_number = rand() % 100 + 1;

	if (random_number <= 50)
	{
		std::cout << "Makes drilling noises." << std::endl;
		std::cout << "The " << _target << " has been successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << "Makes drilling noises." << std::endl;
		std::cout << "The robotomization operation of the " << _target << " has failed." << std::endl;
	}
}

std::string const RobotomyRequestForm::getTarget() const
{
	return(_target);
}