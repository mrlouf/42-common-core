/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:11:32 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 16:11:28 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>

class Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer &operator=(const Serializer &other);
		Serializer(const Serializer &other);

	public:
		static uintptr_t serialize(Data* ptr);
		// It takes a pointer and converts it to the unsigned integer type uintptr_t.

		static Data* deserialize(uintptr_t raw);
		// It takes an unsigned integer parameter and converts it to a pointer to Data.
	
	class NullPointerException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif
