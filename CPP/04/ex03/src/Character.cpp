/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:50:21 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 16:10:06 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

Character::Character()
{
	_name = "Anonymous";
	_floor_size = 0;
	_floor = new AMateria *[_floor_size + 1];
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name)
{
	_name = name;
	_floor_size = 0;
	_floor = new AMateria *[_floor_size + 1];
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &character)
{
    _name = character._name;
    _floor_size = character._floor_size;
    _floor = new AMateria*[_floor_size];
    for (unsigned int i = 0; i < _floor_size; i++) {
        _floor[i] = character._floor[i]->clone();
    }
    for (int i = 0; i < 4; i++) {
        if (character._inventory[i] != NULL)
            _inventory[i] = character._inventory[i]->clone();
		else
            _inventory[i] = NULL;
    }
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	for (unsigned int i = 0; i < _floor_size; i++)
		delete _floor[i]; // Delete floor, ie. inventory that was unequipped
	delete[] _floor;
}

Character &Character::operator=(const Character &character)
{
	if (this != &character)
	{
		_name = character._name;

		for (int i = 0; i < 4; i++)
			if (_inventory[i])
				delete _inventory[i]; // Delete old inventory
		for (unsigned int i = 0; i < _floor_size; i++)
			delete _floor[i]; // Delete old floor
		delete[] _floor;

		_floor_size = character._floor_size;
		_floor = new AMateria *[_floor_size];
		for (unsigned int i = 0; i < 4; i++)
			_floor[i] = character._floor[i]->clone(); // Copy floor also
		for (int i = 0; i < 4; i++)
		{
			if (character._inventory[i] != NULL)
				_inventory[i] = character._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		AMateria **tmp = new AMateria *[_floor_size + 1];
		for (unsigned int i = 0; i < _floor_size; i++)
		{
			tmp[i] = _floor[i]->clone();
			delete _floor[i];
		}
		delete[] _floor;
		tmp[_floor_size] = _inventory[idx];
		_floor_size++;
		_floor = tmp;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
}
