/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:32:42 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/13 12:24:55 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Good morning Harl" << std::endl << std::endl;
}

Harl::~Harl() {
	std::cout << std::endl << "Goodbye Harl" << std::endl;
}

void Harl::_debug() {
	std::cout << "Debug: All systems ok, nothing to complain about." << std::endl;
}

void Harl::_info() {
	std::cout << "Info: Is this a bug? Nah, probably nothing." << std::endl;
}

void Harl::_warning() {
	std::cout << "Warning: Uh-oh, I probably should fix this." << std::endl;
}

void Harl::_error() {
	std::cout << "Error: FCK this stupid code I hate C++ and the whole world" << std::endl;
}

void Harl::complain( std::string level ) {
	
	        // Array of pointers to member functions
        void (Harl::*functions[])() = {
            &Harl::_debug,
            &Harl::_info,
            &Harl::_warning,
            &Harl::_error
        };

        // Array of corresponding level strings
        std::string levels[] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };

        // Call the appropriate function based on the level
        for (int i = 0; i < 4; ++i) {
            if (levels[i] == level) {
                (this->*functions[i])();
                return;
            }
        }

		std::cout << "Harl: I did not recognise this level of complaint: ";
		std::cout << level << " so I'll go get a coffee" << std::endl;
}
