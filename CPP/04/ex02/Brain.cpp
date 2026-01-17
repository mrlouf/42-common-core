/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:56:06 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 15:00:26 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Initialises the brain with the array, sets all ideas to empty string
// since std::string cannot be NULL (to my knowledge)
Brain::Brain() {
	std::cout << "Default Brain constructed" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructed" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i)	// copy all ideas from array
			ideas[i] = other.ideas[i];
	}
	return *this;
}

// Brain needs to delete array of ideas before it is itself deleted in Cat or Dog
Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(std::string idea, unsigned int i) {
	if (i < 100)
		ideas[i] = idea;
	else
		std::cerr << "Index out of range" << std::endl;
}

std::string Brain::getIdea(unsigned int i) const {
	if (i < 100)
		return ideas[i];
	std::cerr << "Index out of range" << std::endl;
	return "";
}
