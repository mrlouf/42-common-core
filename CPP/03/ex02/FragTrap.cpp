/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:52:22 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 14:25:04 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "Default FragTrap steps in the arena!" << std::endl;
	
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap " << name << " steps in the arena!" << std::endl;
	
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "FragTrap " << getName() << " successfully cloned!" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " left the battefield!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " makes a round of high-fives in the room!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, FragTrap &f) {
	out << f.getName();
	return out;
}
