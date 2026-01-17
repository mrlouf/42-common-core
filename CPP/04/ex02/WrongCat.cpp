/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:01:23 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 12:06:29 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";

	std::cout << type << " constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << type << " destroyed" << std::endl;
}
