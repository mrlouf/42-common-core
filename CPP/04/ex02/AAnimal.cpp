/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 13:47:36 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "Default AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destroyed" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::setType(std::string newType) {
	this->type = newType;
}
