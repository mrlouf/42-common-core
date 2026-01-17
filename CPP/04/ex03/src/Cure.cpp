/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:38:41 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 14:26:34 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() {
	type = "cure";
}

Cure::Cure(const Cure &cure) : AMateria(cure) {
	*this = cure;
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &cure) {
	if (this != &cure) {
		type = cure.type;
	}
	return *this;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
