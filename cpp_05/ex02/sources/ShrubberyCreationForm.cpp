#include "../includes/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : Form("Unknown", 145, 137), _target("Anywhere"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : Form(name, 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm	&copy) : Form(copy){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& op)
{
	if (this != &op)
	{
		Form::operator=(op);
	}
	return(*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	makeit();
}

void	ShrubberyCreationForm::makeit(void) const
{
    std::ofstream file(this->_target + "_shrubbery");
    
    for (int i = 0; i < 5; i++)
    {
        file << "    *\n";
        file << "   ***\n";
        file << "  *****\n";
        file << " *******\n";
        file << "    *\n\n";
    }
    
    file.close();
}

std::string const ShrubberyCreationForm::getTarget() const
{
	return(_target);
}