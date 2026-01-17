/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:23:08 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/13 18:32:32 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string str ) {
	if (str.empty())
		_type = "his mighty void puntero";
	else
		_type = str;
}

Weapon::~Weapon() {}

std::string Weapon::getType() {
	return _type;
}

void Weapon::setType( std::string weapon ) {
	if (weapon.empty())
		_type = "his mighty void puntero";
	_type = weapon;
}