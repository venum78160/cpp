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


	Fixed operator+(const Fixed& op) const;
	Fixed operator-(const Fixed& op) const;
	Fixed operator*(const Fixed& op) const;
	Fixed operator/(const Fixed& op) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	bool operator>(Fixed const & op) const;
	bool operator<(Fixed const & op) const;
	bool operator>=(Fixed const & op) const;
	bool operator<=(Fixed const & op) const;
	bool operator==(Fixed const & op) const;
	bool operator!=(Fixed const & op) const;

	static Fixed &min(Fixed &u, Fixed &v);
	const static Fixed &min(const Fixed &u, const Fixed &v);
	static Fixed &max(Fixed &u, Fixed &v);
	const static Fixed &max(const Fixed &u, const Fixed &v);

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);