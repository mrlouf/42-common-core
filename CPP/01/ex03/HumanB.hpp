/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:12:17 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 17:45:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB {
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB();
		HumanB( std::string str );
		~HumanB();
		void setWeapon( Weapon &weapon );
		void attack();
};

#endif