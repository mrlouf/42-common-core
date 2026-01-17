/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:10:01 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 16:24:30 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Usage: ./serializer <any_value>" << std::endl;
		return (1);
	}
	{
		std::cout << "\033[1;31mTest with regular data structure\033[0m" << std::endl;
		try {
			// instanciate Data with av[1] converted to int;
			Data *ptr = new Data;
			ptr->value = (atoi(av[1]));
			ptr->string = "cucufu";

			uintptr_t raw = Serializer::serialize(ptr);
			std::cout << "Serialised value: " << raw << std::endl;

			Data *tmp = Serializer::deserialize(raw);
			std::cout << "Deserialised value: " << tmp->value << std::endl;
			std::cout << "Deserialised value: " << tmp->string << std::endl;

			delete ptr;
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;31mTest with null pointer\033[0m" << std::endl;
		try {
			// instanciate Data with av[1] converted to int;
			Data *ptr = new Data;
			ptr->value = (atoi(av[1]));
			ptr->string = "cucufu";

			uintptr_t raw = Serializer::serialize(NULL);
			std::cout << "Serialised value: " << raw << std::endl;

			Data *tmp = Serializer::deserialize(raw);
			std::cout << "Deserialised value: " << tmp->value << std::endl;
			std::cout << "Deserialised value: " << tmp->string << std::endl;

			delete ptr;
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

	return (0);
}
