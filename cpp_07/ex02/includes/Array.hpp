#pragma once
#include <iostream>
#include <string>
#include <exception>


template<typename T>
class Array
{
private:
	T 				*_array;
	unsigned int	_size;
public:
	Array() : _array(nullptr), _size(0){}
	Array(unsigned int n) : _array(new T[n]), _size(n){}
	Array(const Array &other) : _array(new T[other._size]), _size(other._size)
	{
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = other._array[i];
        }
	}
	Array<T>	&operator=(const Array &op)
	{
		if (this != &op)
		{
			this->_size = op._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
			{
                _array[i] = op._array[i];
            }
		}
		return (*this);
	}
	T	&operator[](unsigned int index)
	{
		if(index >= this->_size)
			throw std::out_of_range("Index is out of range");
		if(this->_array == nullptr)
			throw (std::exception());
		return this->_array[index];
	}
	~Array()
	{
		delete[] _array;
	}
	unsigned int	size( void ) const { return (this->_size); }
};
