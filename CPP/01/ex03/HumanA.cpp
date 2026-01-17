/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 17:31:12 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string str, Weapon &weap ) : _name(str), _weapon(weap) {
}

HumanA::~HumanA() {}

void	HumanA::attack() {
	
	std::string weaponType = _weapon.getType();

	std::cout << _name << " attacks with " << weaponType << std::endl;
}