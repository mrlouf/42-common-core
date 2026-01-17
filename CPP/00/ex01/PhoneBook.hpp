/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:00:18 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 14:47:35 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <sstream>
#include <exception>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		int _index;

	public:
		void displayAll( PhoneBook book );
		void displayContact( PhoneBook& book, int index );
		int getIndex( void );
		void addContact( PhoneBook& book );
		void setIndex( int index );
		Contact getContact ( PhoneBook& book, int index );
};

#endif