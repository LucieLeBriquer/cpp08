/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:10:28 by lle-briq          #+#    #+#             */
/*   Updated: 2022/01/09 22:07:33 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

Span::Span(void) : _N(0), _stored(0)
{
	return ;
}

Span::Span(const unsigned int N) : _N(N), _stored(0)
{
	return ;
}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span()
{
	_data.clear();
}

/*
**		OVERLOAD OPERATORS
*/

Span	&Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->_data.clear();
		this->_N = span._N;
		this->_stored = span._stored;
		this->_data = span._data;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Span &span)
{
	span.printData(o);
	return (o);
};

/*
**		MEMBER FUNCTIONS
*/

void	Span::addNumber(const int n)
{
	if (_stored >= _N)
		throw Span::alreadyFull();
	_data.push_back(n);
	_stored++;
}

int		Span::longestSpan(void) const
{
	if (_stored <= 1)
		throw Span::notEnoughNumbers();

	vectIt	minIt = std::min_element(_data.begin(), _data.end());
	vectIt	maxIt = std::max_element(_data.begin(), _data.end());

	return (*maxIt - *minIt);
}

int		Span::shortestSpan(void) const
{
	if (_stored <= 1)
		throw Span::notEnoughNumbers();
	
	vectIt	minIt = std::min_element(_data.begin(), _data.end());
	int		secondMin;

	if (minIt == _data.begin())
		secondMin = *std::min_element(_data.begin() + 1, _data.end());
	else if (minIt + 1 == _data.end())
		secondMin = *std::min_element(_data.begin(), _data.end() - 1);
	else
		secondMin = std::min(*std::min_element(_data.begin(), minIt - 1), *std::min_element(minIt + 1, _data.end()));
	return (secondMin - *minIt);
}

void	Span::printData(std::ostream &o, const unsigned int max) const
{
	o << "[ ";
	for (unsigned int i = 0; i < max && i < _stored; i++)
		o << _data[i] << " ";
	if (_stored > max)
		o << "... " << _data[_stored - 1] << " ";
	o << "] (" << _stored << "/" << _N << ")";
}
