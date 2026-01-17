/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:07:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 11:33:34 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	
	type = "Dog";

	std::cout << type << " created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {

	*this = other;
}

Dog &Dog::operator=(const Dog &other) {

	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Dog::~Dog() {

	std::cout << type << " destroyed" << std::endl;
}

void Dog::makeSound() const {

	std::cout << type << " goes waf-waf 🐩" << std::endl;

}
