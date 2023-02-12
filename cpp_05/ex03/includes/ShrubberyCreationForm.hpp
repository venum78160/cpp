#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name, std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm	&copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& op);

	void	execute(Bureaucrat const & executor) const;
	void	makeit(void) const;

	std::string const getTarget() const;
};
