/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:47:55 by lle-briq          #+#    #+#             */
/*   Updated: 2022/01/09 15:06:05 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iomanip>
#define SIZE 52

static void	printTitle(std::string title, bool toUpper = true)
{
	std::string		toPrint;
	unsigned int	size = (SIZE > 10 ? SIZE : 10);
	unsigned int	n;

	toPrint = " " + title + " ";
	if (toUpper)
	{
		for (int i = 0; toPrint[i]; i++)
			toPrint[i] = toupper(toPrint[i]);
	}
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n - n / 2);
	std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}

int	main(void)
{
	{
		printTitle("test subject");
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		printTitle("test exception");
		Span	sp = Span(3);

		sp.addNumber(5);
		std::cout << sp << std::endl;

		try
		{		
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{		
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{	
			sp.addNumber(6);
			std::cout << sp << std::endl;
			sp.addNumber(7);
			std::cout << sp << std::endl;
			sp.addNumber(8);
			std::cout << sp << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
