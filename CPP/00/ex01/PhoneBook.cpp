/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:00:06 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 14:45:48 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "PhoneBook.hpp"

Contact PhoneBook::getContact( PhoneBook& book, int index ) {
    return book._contacts[index];
}

void PhoneBook::setIndex(int index) {
    _index = index;
}

void setIndex(PhoneBook& book, int index) {
    book.setIndex(index);
}

int PhoneBook::getIndex( void ) {
	
	std::string input;
	int index;

    std::cout << "36 15 Minitel> enter an index: ";
	
	while (true) {
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			return (-1);
		}
		if (!input.empty()) {
			break;
		}
	}

	if (input.compare("EXIT") == 0 || input.compare("exit") == 0)
	{
		return (-1);
	}

	if (input.find_first_not_of("0123456789+-") != std::string::npos) {
		std::cerr << "Invalid input: only digits and '+' or '-' signs are allowed" << std::endl;
		return (-1);
	}

	std::stringstream ss(input);

	ss >> index;

	try	{
		if ( index <= 0 ) {
      		throw std::invalid_argument( "index is null or negative" );
		}
		else if ( index > 8 ) {
        	throw std::invalid_argument( "index is out of range" );
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (-1);
	}

	return index;
}

void printColumn(const std::string& str) {

	std::string output = str;
	if (output.length() > 10) {
		output = output.substr(0, 9) + ".";
		std::cout << output;
	}
	else
		std::cout << std::setw(10) << std::setfill(' ') << output;
	
}

void PhoneBook::displayContact( PhoneBook& book, int index ) {

	Contact contact = book.getContact(book, index - 1);

	if (index <= book._index) {
		index--;
		std::cout << std::endl;
		std::cout << "First Name: " << contact.getFirstName() << std::endl;
		std::cout << "Last Name:  " << contact.getLastName() << std::endl;
		std::cout << "Nickname:   " << contact.getNickname() << std::endl;
		std::cout << "Phone:      " << contact.getPhoneNumber() << std::endl;
		std::cout << "Secret:     " << contact.getDarkestSecret() << std::endl;
		std::cout << std::endl;
	}
}

void PhoneBook::displayAll( PhoneBook book ) {

	std::cout << std::endl;
    std::cout << "*___________________________________________*" << std::endl;
    std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

	if (book._index == 0) {
		std::cout << std::endl;
		std::cout << "Contact list is empty!" << std::endl;
		std::cout << std::endl;
		return ;
	}

	int	limit = book._index;
	if (book._index > 8)
		limit = 8;

	for (int i = 0; i < limit; i++) {
		
        Contact contact = book._contacts[i];
        std::cout << "|" << std::setw(10) << std::right << i + 1;
		std::cout << "|";
        printColumn(contact.getFirstName());
        std::cout << "|";
        printColumn(contact.getLastName());
        std::cout << "|";
        printColumn(contact.getNickname());
        std::cout << "|" << std::endl;

    }
	
	std::cout << std::endl;

	int index = getIndex();
	if (index == -1)
		return;

	displayContact(book, index);
}

void PhoneBook::addContact(PhoneBook& book) {

	Contact contact;
	contact.createContact();

	if (book._index >= 8) {
		std::cerr << "36 15 Minitel> PhoneBook was full, oldest contact overwritten" << std::endl;
		book._contacts[_index % 8].~Contact();
	}
	else
		std::cout << "36 15 Minitel> New contact added!" << std::endl;
	book._contacts[_index % 8] = contact;
	book._index++;
}
