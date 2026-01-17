/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:07:20 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 11:32:58 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	
	const std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (Intern::*formCreators[3])(std::string) const = {
		&Intern::createPresidential,
		&Intern::createRobotomy,
		&Intern::createShrubbery
	};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	std::cout << "Intern cannot create invalid form " << name << std::endl;
	return NULL;
}

AForm* Intern::createPresidential(std::string target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomy(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(std::string target) const {
	return new ShrubberyCreationForm(target);
}