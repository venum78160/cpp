#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"


class PresidentialPardonForm : public Form
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, std::string target);
	PresidentialPardonForm(const PresidentialPardonForm	&copy);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm& op);

	void	execute(Bureaucrat const & executor) const;
	void	makeit(void) const;

	std::string const getTarget() const;
};
