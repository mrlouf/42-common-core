/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:20:59 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 14:06:36 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

bool ScalarConverter::isChar(const std::string &literal) {
	if (literal.length() != 1 || (literal[0] >= '0' && literal[0] <= '9'))
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string &literal) {
	for (size_t i = 0; i < literal.length(); i++) {
		if (!i && (literal[i] == '+' || literal[i] == '-'))
			continue;
		if (!isdigit(literal[i]))
			return false;
	}

	std::istringstream ss(literal);
	int res;
	ss >> res;
	if (ss.fail())
		return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;

	if (literal[literal.size() - 1] != 'f' && literal[literal.size() - 1] != 'F')
		return false;

	std::istringstream ss(literal);
	float res;
	ss >> res;
	if (ss.fail())
		return false;

	std::string tmp = literal;
	tmp = literal.substr(0, literal.size() - 1);

	errno = 0;
	char *end;
	strtof(tmp.c_str(), &end);
	if (errno == ERANGE || *end != '\0')
		return false;

	return true;
}

bool ScalarConverter::isDouble(const std::string &literal) {
	
	if (literal == "-inf" || literal == "+inf" || literal == "nan" )
		return true;

	errno = 0;
	char *end;
	strtod(literal.c_str(), &end);
	if (errno == ERANGE || *end != '\0')
		return false;
	return true;
}

char ScalarConverter::toChar(const std::string &literal)
{
	char res = literal[0];
	if (!isprint(res))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << res << "'" << std::endl;
	return res;
}

int ScalarConverter::toInt(const std::string &literal) {
	
	std::istringstream ss(literal);
	int res;
	ss >> res;
	if (ss.fail())
		std::cout << "int: impossible" << std::endl;
	return res;
}

float ScalarConverter::toFloat(const std::string &literal) {

	if (literal == "-inff")
		return -std::numeric_limits<float>::infinity();
	else if (literal == "+inff" || literal == "inff")
		return std::numeric_limits<float>::infinity();
	else if (literal == "nanf")
		return std::numeric_limits<float>::quiet_NaN();

	std::istringstream ss(literal);
	float res;
	ss >> res;
	if (ss.fail())
		std::cout << "float: impossible" << std::endl;
	return res;
}

double ScalarConverter::toDouble(const std::string &literal) {

	if (literal == "-inf")
		return -std::numeric_limits<double>::infinity();
	else if (literal == "+inf" || literal == "inf")
		return std::numeric_limits<double>::infinity();
	else if (literal == "nan")
		return std::numeric_limits<double>::quiet_NaN();

	std::istringstream ss(literal);
	double res;
	ss >> res;
	if (ss.fail())
		throw ImpossibleConversionException();
	return res;
}

void ScalarConverter::convert(const std::string &literal) {

	// std::cout << isChar(literal) << std::endl;
	// std::cout << isInt(literal) << std::endl;
	// std::cout << isFloat(literal) << std::endl;
	// std::cout << isDouble(literal) << std::endl;

	enum Type { CHAR, INT, FLOAT, DOUBLE, UNKNOWN };
	Type type = UNKNOWN;

	if (isChar(literal)) {
		type = CHAR;
	} else if (isInt(literal)) {
		type = INT;
	} else if (isFloat(literal)) {
		type = FLOAT;
	} else if (isDouble(literal)) {
		type = DOUBLE;
	}

	switch (type) {
		case CHAR: {
			char c = toChar(literal);
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
			break;
		}
		case INT: {
			int i = toInt(literal);

			if (isascii(i)) {
				if (isprint(static_cast<char>(i)))
					std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
				else
					std::cout << "char: non displayable" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;

			std::cout << "int: " << i << std::endl;

			std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;

			std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
			break;
		}
		case FLOAT: {
			float f = toFloat(literal);

			if (isascii(f)) {
				if (isprint(static_cast<char>(f)))
					std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
				else
					std::cout << "char: non displayable" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;

			if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() \
				|| std::isinf(f) || std::isinf(-f) || std::isnan(f))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(f) << std::endl;

			std::cout << "float: " << f << "f" << std::endl;
			
			std::cout << "double: " << static_cast<double>(f) << std::endl;
			break;
		}
		case DOUBLE: {
			double d = toDouble(literal);

			if (isascii(d)) {
				if (isprint(static_cast<char>(d)))
					std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
				else
					std::cout << "char: non displayable" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;

			if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() \
				|| std::isinf(d) || std::isinf(-d) || std::isnan(d))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;

			if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
				std::cout << "float: impossible" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

			std::cout << "double: " << d << std::endl;
			break;
		}
		default:
			throw InvalidTypeException();
	}
}

const char* ScalarConverter::InvalidTypeException::what() const throw() {
	return "unrecognised literal";
}

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return "non displayable";
}

const char* ScalarConverter::ImpossibleConversionException::what() const throw() {
	return "conversion impossible";
}
