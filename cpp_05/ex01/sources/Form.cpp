#include "../includes/Form.hpp"


Form::Form() : _name("Unknow"), _requiredSignGrade(150), _requiredExecuteGrade(150), _issigned(false)
{
}

Form::Form(std::string name, int SGrade, int EGrade) : _name(name), _requiredSignGrade(SGrade), _requiredExecuteGrade(EGrade), _issigned(false)
{
	if (SGrade > 150 || EGrade > 150)
		throw GradeTooLowException();
	else if (SGrade < 1 || EGrade < 1) 
		throw GradeTooHighException();

}

Form::Form(const Form	&copy) : _name(copy._name), _requiredSignGrade(copy._requiredSignGrade), _requiredExecuteGrade(copy._requiredExecuteGrade), _issigned(copy._issigned)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form& op)
{
	if (this != &op)
	{
		this->_issigned = op._issigned;
	}

	return(*this);
}

void	Form::beSigned(Bureaucrat const &worker)
{
	if (worker.getGrade() > _requiredSignGrade)
		throw(GradeTooLowException());
	_issigned = true;
}

std::string const Form::getName() const
{
	return(_name);
}
int Form::getRequiredSignGrade() const
{
	return _requiredSignGrade;
}
int Form::getRequiredExecuteGrade() const { return _requiredExecuteGrade; }
bool Form::getIsSigned() const { return _issigned; }

std::ostream &operator<<(std::ostream &o, Form const &obj)
{
	o << obj.getName() << ", requires sign grade " << obj.getRequiredSignGrade()
	  << " and execute grade " << obj.getRequiredExecuteGrade();
	if (obj.getIsSigned())
		o << ", is signed";
	else
		o << ", is not signed";
	return o;
}