/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 13:47:36 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Default Animal constructed" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string newType) {
	this->type = newType;
}

void Animal::makeSound() const {

	std::cout << type << " does Animal sounds" << std::endl;
	
}
