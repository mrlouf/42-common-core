/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:07:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 15:53:27 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	
	type = "Dog";
	_brain = new Brain;

	std::cout << type << " created" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << type << " copy constructed" << std::endl;

	type = other.type;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << type << " assignment operator" << std::endl;
	if (this != &other) {
        AAnimal::operator=(other);
        type = other.type;
        delete _brain; // Delete existing _brain
        _brain = new Brain(*other._brain); // Deep copy of _brain
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << type << " destroyed" << std::endl;
}

void Dog::makeSound() const {

	std::cout << type << " goes waf-waf 🐩" << std::endl;

}

Brain* Dog::getBrain() const {
	return _brain;
}
