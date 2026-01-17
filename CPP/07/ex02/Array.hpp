/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:13:41 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/12 14:52:29 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>

class Array {
	private:
		T 				*_elem;
		unsigned int	_size;
	public:
		Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		Array(const unsigned int n);

		unsigned int size() const;

		T &operator[](const unsigned int i);

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

# include "Array.tpp"

#endif
