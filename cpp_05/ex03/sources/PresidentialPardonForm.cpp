#include "../includes/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : Form("Unknown", 25, 5), _target("Anywhere"){}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target) : Form(name, 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm	&copy) : Form(copy){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& op)
{
	if (this != &op)
	{
		Form::operator=(op);
	}
	return(*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	makeit();
}

void	PresidentialPardonForm::makeit(void) const
{
	std::cout << "The " << _target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}

std::string const PresidentialPardonForm::getTarget() const
{
	return(_target);
}