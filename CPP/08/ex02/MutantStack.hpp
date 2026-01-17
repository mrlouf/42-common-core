/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:39:02 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/20 09:40:36 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	private:
	public:
		// Typedefs for iterator support
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		// Coplien's dingsbums
        MutantStack() : std::stack<T, std::deque<T> >() {}
        MutantStack(const MutantStack &other) : std::stack<T, std::deque<T> >(other) {}
        ~MutantStack() {}

        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T, std::deque<T> >::operator=(other);
            return *this;
        }

		// Iterators from underlying container deque
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
