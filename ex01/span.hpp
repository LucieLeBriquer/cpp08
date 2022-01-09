/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:04:33 by lle-briq          #+#    #+#             */
/*   Updated: 2022/01/09 22:09:33 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <vector>
# include <iostream>

class Span
{
	private:
		unsigned int		_N;
		unsigned int		_stored;
		std::vector<int>	_data;
		Span(void);

	public:
		Span(const unsigned int N);
		Span(const Span &span);
		virtual ~Span();

		Span	&operator=(const Span &span);

		// member functions
		void	addNumber(const int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	printData(std::ostream &o, const unsigned int max = 10) const;

		// templated functions
		template<typename T> void	fillRange(typename T::iterator begin, typename T::iterator end);

		// exceptions
		class alreadyFull : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					 return ("Span::Exception : data is full");
				}
		};

		class notEnoughNumbers : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					 return ("Span::Exception : not enough numbers");
				}
		};

};

std::ostream	&operator<<(std::ostream &o, const Span &span);

typedef std::vector<int>::const_iterator vectIt;

/*
**		TEMPLATES
*/

template<typename T> void	Span::fillRange(typename T::iterator begin, typename T::iterator end)
{
	typename T::iterator	it;

	it = begin;
	while (it != end)
	{
		addNumber(*it);
		it++;
	}
}

#endif
