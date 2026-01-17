/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:03:45 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 14:10:05 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap A("Robochiotte");
	ScavTrap B("Moulipute");

	for (int i = 0; i < 2; i++) {
	A.attack("Moulipute");
	}
	
	ScavTrap clone = A;
	clone.setName("Clone");

	for (int i = 0; i < 3; i++) {
	A.guardGate();
	}
	clone.guardGate();

	std::cout << clone << " has " << clone.getEnergyPoints() << " Energy points left" << std::endl;
	clone.attack("Normiprout");
	std::cout << clone << " has " << clone.getEnergyPoints() << " Energy Points left" << std::endl;

	A.takeDamage(8);
	A.beRepaired(5);

	ClapTrap C;
	C.attack("Normiprout");
	C.beRepaired(4);

	return (0);
}
