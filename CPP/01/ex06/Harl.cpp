/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:32:42 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/13 12:28:37 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

	Harl::Harl() {
	std::cout << "Good morning Harl" << std::endl << std::endl;
}

	Harl::~Harl() {
		std::cout << std::endl << "Goodbye Harl" << std::endl;
}

void Harl::complain( std::string level ) {
	
	enum Level {
		DEBUG = 1,
		INFO,
		WARNING,
		ERROR
	};

	int i = 0;
	if (level == "DEBUG") i = DEBUG;
	if (level == "INFO") i = INFO;
	if (level == "WARNING") i = WARNING;
	if (level == "ERROR") i = ERROR;

	switch (i) {
	case 1:
		std::cout << "Debug: All systems ok, nothing to complain about." << std::endl;
	case 2:
		std::cout << "Info: Is this a bug? Nah, probably nothing." << std::endl;
	case 3:
		std::cout << "Warning: Uh-oh, I probably should fix this." << std::endl;
	case 4:
		std::cout << "Error: FCK this stupid code I hate C++ and the whole world" << std::endl;
		break ;
	default:
		std::cout << "Harl: I did not recognise this level of complaint: ";
		std::cout << level << " so I'll go get a coffee" << std::endl;
	}
}
