/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:05:51 by lle-briq          #+#    #+#             */
/*   Updated: 2022/01/08 01:41:03 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include "easyfind.hpp"
#define YELLOW "\x1B[33m"
#define END "\x1B[0m"
#define SIZE 52

static void	display(int a)
{
	std::cout << a << " ";
}

static void	printTitle(std::string title)
{
	std::string		toPrint;
	unsigned int	size = (SIZE > 10 ? SIZE : 10);
	unsigned int	n;

	toPrint = " " + title + " ";
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

static void	printSubtitle(const std::string subtitle)
{
	std::cout << std::endl << YELLOW << subtitle << END << std::endl;
}

int	main(void)
{
	{
		printTitle("INT LIST");

		printSubtitle("Init list<int>");
		std::list<int>	lst;
		for (int i = 0; i < 10; i++)
			lst.push_back(i);
		std::for_each(lst.begin(), lst.end(), display);
		std::cout << std::endl;

		printSubtitle("Item found in list<int>");
		std::cout << "value at easyfind(lst, 5) is " << *(easyfind(lst, 5)) << std::endl;

		printSubtitle("Print list<int> from the found iterator");
		std::for_each(easyfind(lst, 5), lst.end(), display);
		std::cout << std::endl;

		printSubtitle("Item can't be found in list<int>");
		std::cout << "easyfind(lst, 12) == lst.end() ? " << ((lst.end() == easyfind(lst, 12)) ? "true" : "false") << std::endl;
	}
	{
		printTitle("INT VECTOR");

		printSubtitle("Init vect<int>");
		int	fill[] = {1, 5, 2, 4, 7, 10, 5};
		std::vector<int>	vect(fill, fill + 7);
		std::for_each(vect.begin(), vect.end(), display);
		std::cout << std::endl;

		printSubtitle("Item found in vect<int>");
		std::cout << "value at easyfind(vect, 5) is " << *(easyfind(vect, 5)) << std::endl;

		printSubtitle("Print list<int> from the found iterator");
		std::for_each(easyfind(vect, 5), vect.end(), display);
		std::cout << std::endl;

		printSubtitle("Item can't be found in vect<int>");
		std::cout << "easyfind(vect, 12) == vect.end() ? " << ((vect.end() == easyfind(vect, 12)) ? "true" : "false") << std::endl;
	}
	return (0);
}
