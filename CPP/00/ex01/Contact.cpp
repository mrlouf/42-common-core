/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:02:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 14:48:15 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <stdlib.h>

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

std::string getFirstName(Contact& contact) {
    return contact.getFirstName();
}

std::string getLastName(Contact& contact) {
    return contact.getLastName();
}

std::string getNickname(Contact& contact) {
    return contact.getNickname();
}

std::string getPhoneNumber(Contact& contact) {
    return contact.getPhoneNumber();
}

std::string getDarkestSecret(Contact& contact) {
    return contact.getDarkestSecret();
}

Contact Contact::createContact( void ) {

	Contact newContact;

	do {
		std::cout << "36 15 Minitel> Enter first name: ";
		std::getline(std::cin, _firstName);
		if (std::cin.eof()) {
			exit (1);
		}
		if (_firstName.empty()) {
			std::cout << "First name cannot be empty. Please try again." << std::endl;
		}
	} while (_firstName.empty());
	newContact._firstName = _firstName;

	do {
		std::cout << "36 15 Minitel> Enter last name: ";
		std::getline(std::cin, _lastName);
		if (std::cin.eof()) {
			exit (1);
		}
		if (_lastName.empty()) {
			std::cout << "Last name cannot be empty. Please try again." << std::endl;
		}
	} while (_lastName.empty());
	newContact._lastName = _lastName;

	do {
		std::cout << "36 15 Minitel> Enter nickname: ";
		std::getline(std::cin, _nickname);
		if (std::cin.eof()) {
			exit (1);
		}
		if (_nickname.empty()) {
			std::cout << "Nickname cannot be empty. Please try again." << std::endl;
		}
	} while (_nickname.empty());
	newContact._nickname = _nickname;

	do {
		std::cout << "36 15 Minitel> Enter phone number: ";
		std::getline(std::cin, _phoneNumber);
		if (std::cin.eof()) {
			exit (1);
		}
		if (_phoneNumber.empty() || _phoneNumber.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Phone number cannot be empty and must contain digits only. Please try again." << std::endl;
		}
	} while (_phoneNumber.empty() || _phoneNumber.find_first_not_of("0123456789") != std::string::npos);
	newContact._phoneNumber = _phoneNumber;

	do {
		std::cout << "36 15 Minitel> Enter darkest secret: ";
		std::getline(std::cin, _darkestSecret);
		if (std::cin.eof()) {
			exit (1);
		}
		if (_darkestSecret.empty()) {
			std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
		}
	} while (_darkestSecret.empty());
	newContact._darkestSecret = _darkestSecret;
	
	return newContact;
}