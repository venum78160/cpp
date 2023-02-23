#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_vec;
public:
	Span();
	Span(unsigned int nb);
	Span(Span const &cpy);
	Span &operator=(Span const &ot);
	~Span();
	void	addNumber(int nb);
	int		shortestSpan();
	int		longestSpan();
	int		findDist(int f, int s);
	void	addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void	printVec();
	class AnyExecption : public std::exception
	{
		public:
		std::string _message;
		AnyExecption(const std::string &message) throw(): _message(message) {}
		virtual ~AnyExecption(void) throw(){};
		const char *what() const throw()
		{
			return _message.c_str();
		}
	};
};
