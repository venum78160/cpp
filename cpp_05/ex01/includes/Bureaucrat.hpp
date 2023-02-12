#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
protected:
	std::string const _name;
	int			_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat	&copy);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat& op);

	std::string	const	getName() const;
	int					getGrade() const;

	void	increment();
	void	decrement();
	void	signForm(Form &obj) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "The Grade exceeds the acceptable limit! Allowed range: [1, 150]";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return "The Grade falls below the minimum limit! Allowed range: [1, 150]";
		}
	};

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj);