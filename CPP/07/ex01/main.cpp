/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:22:47 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 21:05:05 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void capitalise(char &c)
{
	c = toupper(c);
}

int	main()
{
	{
		std::cout << "\033[31mTest negating integers using template function\033[0m" << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		size_t len = 5;

		std::cout << "Original array: ";
		for (size_t i = 0; i < len; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		iter(arr, len, negate);

		std::cout << "Iterated array: ";
		for (size_t i = 0; i < len; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\033[31mTest capitalising chars using wrapper function\033[0m" << std::endl;
		char arr[] = {'a', 'b', 'c', 'd', 'e'};
		size_t len = 5;

		std::cout << "Original array: ";
		for (size_t i = 0; i < len; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		iter(arr, len, capitalise);

		std::cout << "Iterated array: ";
		for (size_t i = 0; i < len; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	return (0);
}
