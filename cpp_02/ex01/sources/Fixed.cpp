#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed	&copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = copy.value;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << bit_fraction;
}

Fixed::Fixed(const float floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(floater * (1 << bit_fraction));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& op)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = op.value;
	return (*this);
}

int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (float)(1 << this->bit_fraction));
}

int Fixed::toInt(void) const
{
    return ((int)(this->value >> this->bit_fraction));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
    out << fixe.toFloat();
    return (out);
}