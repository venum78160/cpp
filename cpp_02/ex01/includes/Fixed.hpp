#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int	value;
	const static int	bit_fraction = 8;
public:
	Fixed();
	Fixed(const Fixed	&copy);
	Fixed(const int integer);
    Fixed(const float floater);
	~Fixed();
	Fixed &operator=(const Fixed& op);

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);