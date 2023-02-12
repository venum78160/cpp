#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal	&copy);
	virtual ~Animal();
	Animal &operator=(const Animal& op);

	virtual void makeSound() const = 0;
	virtual std::string getType() const;
};
