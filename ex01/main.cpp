/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:47:55 by lle-briq          #+#    #+#             */
/*   Updated: 2022/01/09 22:38:45 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#define YELLOW "\x1B[33m"
#define BOLD "\x1B[1m"
#define END "\x1B[0m"


static void printSubtitle(const std::string subtitle)
{
	static int	i;
	
	if (i > 0)
		std::cout << std::endl;
	else
		i++;
    std::cout << YELLOW << subtitle << END << std::endl;
}

int	main(void)
{
	{
		printSubtitle("Subject");
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;

		std::cout << "shortest span\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span \t" << sp.longestSpan() << std::endl;
	}
	{
		printSubtitle("Exceptions");
		Span	sp = Span(3);

		sp.addNumber(5);
		std::cout << sp << std::endl;

		try
		{
			std::cout << "shortest span\t" << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "?\t";
			std::cerr << e.what() << std::endl;
		}

		try
		{		
			std::cout << "longest span \t" << sp.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "?\t";
			std::cerr << e.what() << std::endl;
		}

		try
		{	
			sp.addNumber(6012);
			std::cout << sp << std::endl;
			sp.addNumber(-791);
			std::cout << sp << std::endl;
			sp.addNumber(832);
			std::cout << sp << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "shortest span\t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span \t" << sp.longestSpan() << std::endl;
	}
	{
		printSubtitle("Lot of data");
		std::vector<int>	vect;
		Span				sp = Span(100000);

		srand(time(NULL));
		for (int i = 1; i <= 100000; i++)
			vect.push_back(i);
		sp.fillRange< std::vector<int> >(vect.begin(), vect.end());
		std::cout << sp << std::endl;
		std::cout << "shortest span \t" << sp.shortestSpan() << std::endl;
		std::cout << "longest span  \t" << sp.longestSpan() << std::endl;
	}
	return (0);
}
