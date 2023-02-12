#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed	&copy)
{
	this->value = copy.value;
}

Fixed::Fixed(const int integer)
{
	this->value = integer << bit_fraction;
}

Fixed::Fixed(const float floater)
{
	this->value = (int)roundf(floater * (1 << bit_fraction));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed & op)
{
	this->value = op.value;
	return (*this);
}

Fixed Fixed::operator+(const Fixed & op) const
{
	Fixed rsl;
	rsl.setRawBits(this->getRawBits() + op.getRawBits());
	return (rsl);
}

Fixed Fixed::operator-(const Fixed & op) const
{
	Fixed rsl;
	rsl.setRawBits(this->getRawBits() - op.getRawBits());
	return(rsl);
}

Fixed Fixed::operator*(const Fixed & op) const
{
	Fixed rsl;
	rsl.setRawBits((this->getRawBits() * op.getRawBits()) >> this->bit_fraction);
	return(rsl);
}

Fixed Fixed::operator/(const Fixed& op) const
{
	Fixed rsl;
	rsl.setRawBits((this->getRawBits() << this->bit_fraction) / op.getRawBits());
	return(rsl);
}

// Pre increment operator.
Fixed & Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

// Post increment operator.

Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    operator++();
    return (result);
}

// Pre decrement operator.

Fixed & Fixed::operator--(void)
{
    this->value--;
    return (*this);
}

// Post decrement operator.

Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    operator--();
    return (result);
}

bool Fixed::operator>(Fixed const & op) const
{
	return (this->getRawBits() > op.getRawBits());
}

bool Fixed::operator<(Fixed const & op) const
{
	return (this->getRawBits() < op.getRawBits());
}

bool Fixed::operator>=(Fixed const & op) const
{
	return (this->getRawBits() >= op.getRawBits());
}

bool Fixed::operator<=(Fixed const & op) const
{
	return (this->getRawBits() <= op.getRawBits());
}

bool Fixed::operator==(Fixed const & op) const
{
	return (this->getRawBits() == op.getRawBits());
}

bool Fixed::operator!=(Fixed const & op) const
{
	return (this->getRawBits() != op.getRawBits());
}


int Fixed::getRawBits(void)const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed &Fixed::min(Fixed &u, Fixed &v)
{
	return (u.value < v.value) ? u : v;
}

const Fixed &Fixed::min(const Fixed &u, const Fixed &v)
{
	return (u.value < v.value) ? u : v;
}

Fixed &Fixed::max(Fixed &u, Fixed &v)
{
	return (u.value > v.value) ? u : v;
}

const Fixed &Fixed::max(const Fixed &u, const Fixed &v)
{
	return (u.value > v.value) ? u : v;
}