/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:08:33 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 18:45:03 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

void	testVector(void)
{
	std::vector<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << "top = " << *(mstack.end() - 1) << std::endl;
	
	mstack.pop_back();

	std::cout << "size = " << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(-12);
	mstack.push_back(0);

	std::vector<int>::iterator	it = mstack.begin();
	std::vector<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	testSubject(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top = " << mstack.top() << std::endl;
	
	mstack.pop();

	std::cout << "size = " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(-12);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack <int>	s(mstack);
}

int	main(void)
{
	testSubject();
	testVector();
	
	return (0);
}
