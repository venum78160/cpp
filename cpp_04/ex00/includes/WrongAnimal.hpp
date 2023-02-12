#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal& op);

	void makeSound() const;
	virtual std::string getType() const;
};
