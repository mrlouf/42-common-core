/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:19 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/07 17:30:55 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include "ScalarConverter.hpp"

int	main(int ac, char **av) {

	if (ac != 2 || strlen(av[1]) == 0) {
		std::cout << "Usage: ./scalarConverter <C++ literal>" << std::endl;
		return 1;
	}

	try {
		ScalarConverter::convert(av[1]);
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
