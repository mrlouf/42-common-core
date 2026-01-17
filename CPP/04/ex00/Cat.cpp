/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:31 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 16:20:04 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";

	std::cout << type << " constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << type << " destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << type << " goes meow-meow 🐈‍" << std::endl;
}
