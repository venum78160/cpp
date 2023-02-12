#pragma once
#include <iostream>
#include <string>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain	&copy);
	virtual ~Brain();
	Brain &operator=(const Brain& op);
};
