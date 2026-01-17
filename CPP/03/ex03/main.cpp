/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:03:45 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 14:29:33 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	{
	
		DiamondTrap D;

	}

	std::cout << std::endl;

	{

		DiamondTrap D = DiamondTrap("Diamond1"); 
		D.whoAmI();
		D.attack("Moulinette");
		D.highFivesGuys();
		D.guardGate();

	}

	return (0);
}
