#include "../includes/Span.hpp"

Span::Span() : _size(0){}

Span::Span(unsigned int nb) : _size(nb){}

Span::Span(Span const &cpy)
{
	_size = cpy._size;
	for (std::vector<int>::const_iterator it = cpy._vec.begin(); it != cpy._vec.end(); it++)
	{
		this->_vec.push_back(*it);
	}
}

Span &Span::operator=(Span const &ot)
{
	_size = ot._size;
	this->_vec.clear();
	for (std::vector<int>::const_iterator it = ot._vec.begin(); it != ot._vec.end(); it++)
	{
		this->_vec.push_back(*it);
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int nb)
{
	if (_vec.size() >= _size)
		throw AnyExecption("Limit of the vector reached. Impossible to add new element to the vector!");
	_vec.push_back(nb);
}

int		Span::findDist(int f, int s)
{
	int res = abs(f - s);
	return (res);
}

int		Span::longestSpan()
{
	if (_size < 2)
		throw AnyExecption("Not enough elements in the vector to find a distance.");
	int max = *std::max_element(_vec.begin(), _vec.end());
	int min = *std::min_element(_vec.begin(), _vec.end());
	return(abs(max - min));
}

int		Span::shortestSpan()
{
	if (_size < 2)
		throw AnyExecption("Not enough elements in the vector to find a distance.");
	int short_dist = std::numeric_limits<int>::max();
	for( std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		for(std::vector<int>::iterator it2 = it + 1; it2 != _vec.end(); it2++)
		{
			int dist = this->findDist(*it, *it2);
			if(dist < short_dist)
				short_dist = dist;
		}
	}
	return (short_dist);
}

void	Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vec.size() + this->findDist(*begin, *(end - 1)) >= _size)
		throw AnyExecption("Limit of the vector reached. Impossible to add new element to the vector!");
	for(std::vector<int>::iterator it = begin; it != end; it++)
		this->addNumber(*it);
}
void	Span::printVec()
{
	for(std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
