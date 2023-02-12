#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	void	annoncement(void) const;
	void	setname(std::string name);
};

Zombie* zombieHorde( int N, std::string name );
