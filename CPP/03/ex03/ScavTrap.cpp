/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:22:43 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 14:20:17 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap joined the fight!" << std::endl;
	
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap " << name << " joined the fight!" << std::endl;
	
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " is now a pile of junk!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ScavTrap " << _name << " successfully cloned!" << std::endl;
	}
	return *this;
}

void ScavTrap::attack(std::string target) {
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " does not have enough energy to attack!";
		std::cout << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attackDamage << " points of damage!";
		std::cout << std::endl;
		_energyPoints--;
	}
}

void ScavTrap::guardGate() {
	if (_guarding) {
		_guarding = false;
		std::cout << "ScavTrap " << _name << " leaving Gate Keeper mode!" << std::endl;
	}
	else {
		_guarding = true;
		std::cout << "ScavTrap " << _name << " entering Gate Keeper mode!" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, ScavTrap &s) {
	out << s.getName();
	return out;
}
