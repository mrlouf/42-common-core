/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:43:03 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/06 13:22:45 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
AForm("PFF", 25, 5), _target("None") {
	std::cout << "PFF created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PFF destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : \
AForm(other), _target(other._target) {
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	(void)other;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : \
AForm("PFF", 25, 5), _target(target) {
	std::cout << "PFF created" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw UnsignedException();
	if (executor.getGrade() <= getExecuteGrade())
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw GradeTooLowException();
}
