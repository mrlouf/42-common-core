/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:11 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/13 12:43:20 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	
	// Dynamically allocate the pointer to return it and use it outside of the function's scope
	Zombie *zombie = new (std::nothrow) Zombie(name);

	return zombie;
}
