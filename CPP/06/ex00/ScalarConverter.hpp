/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:12:35 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/08 20:20:32 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <exception>
# include <cctype>
# include <cstdlib>
# include <cerrno>
# include <cmath>
# include <sstream>
# include <iomanip>
# include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		ScalarConverter(const ScalarConverter &other);

		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);

		static char toChar(const std::string &literal);
		static int toInt(const std::string &literal);
		static float toFloat(const std::string &literal);
		static double toDouble(const std::string &literal);
 
	public:
		static void convert(const std::string &literal);

	class NonDisplayableException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class ImpossibleConversionException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class InvalidTypeException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif
