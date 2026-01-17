/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:02:39 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 13:25:59 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void printWelcomeMessage() {

    std::cout << " +--------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                                                                              |" << std::endl;
    std::cout << "|      WELCOME TO THE (CRAPPY) RETRO PHONEBOOK                                                 |" << std::endl;
    std::cout << "|                                                                                              |" << std::endl;
    std::cout << "|   ██████╗  ██████╗      ██╗███████╗    ███╗   ███╗██╗███╗   ██╗██╗████████╗███████╗██╗       |" << std::endl;
    std::cout << "|   ╚════██╗██╔════╝     ███║██╔════╝    ████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔════╝██║       |" << std::endl;
    std::cout << "|    █████╔╝███████╗     ╚██║███████╗    ██╔████╔██║██║██╔██╗ ██║██║   ██║   █████╗  ██║       |" << std::endl;
    std::cout << "|    ╚═══██╗██╔═══██╗     ██║╚════██║    ██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══╝  ██║       |" << std::endl;
    std::cout << "|   ██████╔╝╚██████╔╝     ██║███████║    ██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ███████╗███████╗  |" << std::endl;
    std::cout << "|   ╚═════╝  ╚═════╝      ╚═╝╚══════╝    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚══════╝╚══════╝  |" << std::endl;
    std::cout << "|                                                                                              |" << std::endl;
    std::cout << "|      Enter ADD to save a new contact                                                         |" << std::endl;
    std::cout << "|      Enter SEARCH to display a specific contact                                              |" << std::endl;
    std::cout << "|      Enter EXIT to quit and lose all contacts forever                                        |" << std::endl;
    std::cout << "|                                                                                              |" << std::endl;
    std::cout << " +--------------------------------------------------------------------------------------------+" << std::endl;

}

std::string getUserInput( void ) {
	
	std::string input;

    std::cout << "36 15 Minitel> ";
	
	while (true) {
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			return ("EXIT");
		}
		if (!input.empty()) {
			break;
		}
	}

    for (size_t i = 0; i < input.length(); ++i) {
        input[i] = std::toupper(input[i]);
    }

	return input;
}

int main( void ) {
	
    printWelcomeMessage();

	PhoneBook book;

	book.setIndex(0);

	std::string input = getUserInput();

	while (!input.empty()) {
		if (input.compare("ADD") == 0 || input.compare("add") == 0)
			book.addContact(book);
		else if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
			book.displayAll(book);
		else if (input.compare("EXIT") == 0 || input.compare("exit") == 0)
		{
			std::cout << "36 15 Minitel> Goodbye!" << std::endl;
			return (0);
		}
		else {
			std::cerr << "36 15 Minitel> Unknown input: \'" << input << "\'" << std::endl;
		};
		input = getUserInput();
	};
	
	return (0);
}
