/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:47:31 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/06 13:18:12 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
AForm("RRF", 72, 45), _target("None") {
	std::cout << "RRF created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RRF destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : \
AForm(other), _target(other._target) {
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	(void)other;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : \
AForm("RRF", 25, 5), _target(target) {
	std::cout << "RRF created" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw UnsignedException();
	if (executor.getGrade() <= getExecuteGrade()) {
		srand(time(NULL));
		std::cout << "BBbbbbbBbbbZZZZzzzZzzzzz *drilling noises*" << std::endl;
		if (rand() % 2 == 0)
			std::cout << _target << " was successfully robotomised! 🤖" << std::endl;
		else
			std::cout << "Oh no, robotomisation of " << _target << " failed!" << std::endl;
	}
	else
		throw GradeTooLowException();
}
