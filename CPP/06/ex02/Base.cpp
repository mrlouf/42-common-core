/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:08:12 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 16:41:17 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Base.hpp"

Base::~Base() {}


Base *generate(void) {

	//srand(time(0));
	int i = rand() % 3;

	std::cout << "Class generated: " << static_cast<char>(i + 65) << std::endl;

	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;

	return new C;
}

void identify(Base* p) {

	// dynamic_cast returns a null pointer in case of failed cast
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unidentified pointer, not a Base class object" << std::endl;
}

void identify(Base& p) {

	// failed cast cannot return null reference, so use try method
	// to catch potential bad cast
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
		;
	}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
		;
	}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &e) {
		;
	}
	std::cout << "Unidentified reference, not a Base class object" << std::endl;

}
