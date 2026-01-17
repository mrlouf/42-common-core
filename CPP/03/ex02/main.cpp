/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:03:45 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 14:21:48 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	{
	ScavTrap A("Robochiotte");
	A.attack("Normipute");
	FragTrap B("Mecanoprout");
	ClapTrap C;
	C.attack("Normipute");
	}

	std::cout << std::endl;

	{
		
	FragTrap B("Mecanoprout");
	B.highFivesGuys();
	B.attack("Normipute");

	}

	return (0);
}
