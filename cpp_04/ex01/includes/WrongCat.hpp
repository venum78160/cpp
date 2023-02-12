#pragma once
#include "WrongAnimal.hpp"
#include "Animal.hpp"

class WrongCat : public WrongAnimal
{
protected:
	std::string type;
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat	&copy);
	~WrongCat();
	WrongCat &operator=(const WrongCat& op);

	void makeSound() const;
	std::string getType() const;
};
