/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:47:32 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 09:37:25 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {

std::string string = "HI THIS IS BRAIN";

std::string *stringPTR = &string;
std::string &stringREF = string;

std::cout << &string << std::endl;
std::cout << stringPTR << std::endl;
std::cout << &stringREF << std::endl;

std::cout << string << std::endl;
std::cout << *stringPTR << std::endl;
std::cout << stringREF << std::endl;

}