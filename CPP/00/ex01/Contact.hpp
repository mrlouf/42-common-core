/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:02:11 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/12 14:47:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		
	public:
		Contact();
		~Contact();
		Contact createContact( void );
		std::string getFirstName( void ) const;
		std::string getLastName( void ) const;
		std::string getNickname( void ) const;
		std::string getPhoneNumber( void ) const;
		std::string getDarkestSecret( void ) const;
};

#endif