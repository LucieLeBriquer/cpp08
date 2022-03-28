/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:06:05 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/28 18:55:40 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:
		
	public:
		MutantStack(void);
		MutantStack(const MutantStack &mstack);
		virtual ~MutantStack();

		MutantStack	&operator=(const MutantStack<T> &mstack);

		// typedef
		typedef	typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;

		// iterators functions
		iterator				begin(void) { return (this->c.begin()); }
		iterator				end(void) { return (this->c.end()); }

		const_iterator			begin(void) const { return (this->c.begin()); }
		const_iterator			end(void) const { return (this->c.end()); }

		reverse_iterator		rbegin(void) { return (this->c.rbegin()); }
		reverse_iterator		rend(void) { return (this->c.rend()); }

		const_reverse_iterator	rbegin(void) const { return (this->c.rbegin()); }
		const_reverse_iterator	rend(void) const { return (this->c.rend()); }

};

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

template<typename T> MutantStack<T>::MutantStack(void)
{
	return ;
}

template<typename T> MutantStack<T>::MutantStack(const MutantStack<T> &mstack)
{
	*this = mstack;
}

template<typename T> MutantStack<T>::~MutantStack()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

template<typename T> MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &mstack)
{
	if (*this != mstack)
		static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(mstack);
	return (*this);
}

#endif
