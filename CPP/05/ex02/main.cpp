/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:55:59 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 11:38:18 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	
	{
		std::cout << "\033[1;31mTest with grade too low to sign, execute\033[0m" << std::endl;
		try {
			Bureaucrat H = Bureaucrat("Hugo", 150);
			PresidentialPardonForm PFF = PresidentialPardonForm("target");
			H.signForm(PFF);
			std::cout << "Exception thrown, continue execution in try-block" << std::endl;
			H.executeForm(PFF);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;31mTest with grade too low to execute\033[0m" << std::endl;
		try {
			Bureaucrat H = Bureaucrat("Hugo", 15);
			PresidentialPardonForm PFF = PresidentialPardonForm("target");
			H.signForm(PFF);
			H.executeForm(PFF);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;31mTest try execute unsigned PFF\033[0m" << std::endl;
		try {
			Bureaucrat H = Bureaucrat("Hugo", 1);
			PresidentialPardonForm PFF = PresidentialPardonForm("Oktorok");
			H.executeForm(PFF);
			H.signForm(PFF);
			H.executeForm(PFF);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;31mTest executing PFF\033[0m" << std::endl;
		try {
			Bureaucrat H = Bureaucrat("Hugo", 1);
			PresidentialPardonForm PFF = PresidentialPardonForm("Oktorok");
			H.signForm(PFF);
			H.executeForm(PFF);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;31mTest Robotomy\033[0m" << std::endl;
		try {
			Bureaucrat H = Bureaucrat("Hugo", 1);
			RobotomyRequestForm RRF("Oktorok");
			H.signForm(RRF);
			H.executeForm(RRF);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "\033[1;31mTest Shrubbery\033[0m" << std::endl;
		try {
			Bureaucrat H = Bureaucrat("Hugo", 1);
			ShrubberyCreationForm SCF("Oktorok");
			H.signForm(SCF);
			H.executeForm(SCF);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
