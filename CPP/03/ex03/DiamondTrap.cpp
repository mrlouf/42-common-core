/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:45:11 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 14:29:26 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "Default DiamondTrap is ready to rumble!" << std::endl;

	_name = "Default";
	ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap " << name << " is ready to rumble!" << std::endl;

	_name = name;
	ClapTrap::_name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), ScavTrap(), FragTrap() {
	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " collapsed!" << std::endl;
}

std::string DiamondTrap::getName() const {
	return _name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const DiamondTrap &d) {
	out << d.getName();
	return out;
}

void DiamondTrap::whoAmI() {
	std::cout << "To be " << _name;
	std::cout <<" or (not) to be " << ClapTrap::_name;
	std::cout << ", that is the question" << std::endl;
}
