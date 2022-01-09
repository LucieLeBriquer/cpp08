/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:04:33 by lle-briq          #+#    #+#             */
/*   Updated: 2022/01/09 14:53:00 by lle-briq         ###   ########.fr       */
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

		
		
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &span);
		virtual ~Span();

		Span	&operator=(const Span &span);

		// member functions
		void	addNumber(int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	printData(std::ostream &o, unsigned int max = 10) const;

		// exceptions
		class alreadyFull : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					 return ("Can't add a new new number (data is already full)");
				}
		};

		class notEnoughNumbers : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					 return ("No span to find (not enough numbers)");
				}
		};

};

std::ostream	&operator<<(std::ostream &o, const Span &span);

typedef std::vector<int>::const_iterator vectIt;

#endif
