/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:03:04 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/06 13:23:00 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
AForm("SCF", 72, 45), _target("None") {
	std::cout << "SCF created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "SCF destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : \
AForm(other), _target(other._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	(void)other;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : \
AForm("SCF", 25, 5), _target(target) {
	std::cout << "RRF created" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw UnsignedException();	
	if (executor.getGrade() <= getExecuteGrade()) {
		std::string name = _target + "_shrubbery";
		std::ofstream shrubbery(name.c_str());

        shrubbery << "       ^\n";
        shrubbery << "      ^^^\n";
        shrubbery << "     ^^^^^\n";
        shrubbery << "    ^^^^^^^\n";
        shrubbery << "   ^^^^^^^^^\n";
        shrubbery << "  ^^^^^^^^^^^\n";
        shrubbery << "       ||\n";
        shrubbery << "       ||\n";

		shrubbery.close();
	}
	else
		throw GradeTooLowException();
}
