/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:16:28 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/13 12:53:44 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main()
{
	Zombie *Bar = newZombie("Bar");

	Bar->announce();

	randomChump("Foo");
	
	// Manual free of allocated pointer
	delete Bar;
	
	return (0);
}
