#include "../includes/Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Unknow"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1) 
		throw GradeTooHighException();
	this->_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat	&copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& op)
{
	if (this != &op)
	{
		this->_grade = op._grade;
	}

	return(*this);
}

std::string const Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

void Bureaucrat::increment()
{
	if (_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(Form &obj) const
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << obj.getName() << " because grade value is too low" << std::endl;
	}	
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "Form " << form.getName() << " has been executed by " << this->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << ", bureaucrat grade is " << obj.getGrade();
	return o;
}