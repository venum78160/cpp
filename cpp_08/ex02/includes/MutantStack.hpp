#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <stack>
#include <iterator>


template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
    const_iterator cbegin() const { return this->c.cbegin(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    const_reverse_iterator crbegin() const { return this->c.crbegin(); }

    iterator end() { return this->c.end(); }
    const_iterator cend() const { return this->c.cend(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator crend() const { return this->c.crend(); }

	MutantStack() {}
    MutantStack(MutantStack<T> const &cpy) : std::stack<T>(cpy) {}
    MutantStack<T> &operator=(MutantStack<T> const &rhs)
    {
        if (this != &rhs)
            std::stack<T>::operator=(rhs);
        return (*this);
    }
    ~MutantStack() {}
};

