/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:55:59 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/06 13:42:22 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {
	
	{
		std::cout << "\033[1;31mTest Intern creating all forms\033[0m" << std::endl;
		Intern I;
		AForm* pp;
		AForm* rr;
		AForm* sc;

		pp = I.makeForm("presidential pardon", "Oktorok");
		rr = I.makeForm("robotomy request", "Oktorok");
		sc = I.makeForm("shrubbery creation", "Oktorok");

		delete pp;
		delete rr;
		delete sc;
	}
	{
		std::cout << std::endl << "\033[1;31mTest Intern cannot create non-existing form\033[0m" << std::endl;
		Intern I;
		AForm* null;

		null = I.makeForm("42", "Oktorok");

		delete null;
	}
	{
		std::cout << std::endl << "\033[1;31mTest Intern creates SCF, Bureaucrat signs & executes\033[0m" << std::endl;
		Bureaucrat B("B", 1);
		Intern I;
		AForm* scf;

		scf = I.makeForm("shrubbery creation", "Oktorok");
		try {
			B.signForm(*scf);
			B.executeForm(*scf);
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception :" << e.what() << std::endl;
		}

		delete scf;
	}
	return (0);
}
