#pragma once
#include <iostream>
#include <string>

class Fixed
{
private:
	int	value;
	const static int	bit_fraction = 8;
public:
	Fixed();
	Fixed(Fixed	&copy);
	~Fixed();
	Fixed &operator=(Fixed& op);

	int	getRawBits(void) const;
	void setRawBits(int const raw);
};