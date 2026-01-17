/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:38:44 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 14:27:02 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() {
	type = "ice";
}

Ice::Ice(const Ice &ice) : AMateria(ice) {
	*this = ice;
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &ice) {
	if(this != &ice)
		type = ice.type;
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
