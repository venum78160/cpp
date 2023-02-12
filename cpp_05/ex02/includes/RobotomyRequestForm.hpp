#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Form.hpp"


class RobotomyRequestForm : public Form
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name, std::string target);
	RobotomyRequestForm(const RobotomyRequestForm	&copy);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm& op);

	void	execute(Bureaucrat const & executor) const;
	void	makeit(void) const;

	std::string const getTarget() const;
};
