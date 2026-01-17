/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:55:59 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 10:23:19 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	
	{
		std::cout << std::endl << "\033[1;31mTest Bureaucrat can sign default Form\033[0m" << std::endl;
		Bureaucrat H = Bureaucrat("Hugo", 10);
		std::cout << H << std::endl;
		Form F;
		try {H.signForm(F);}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
		std::cout << e.what() << std::endl;
		}
		std::cout << F.getIsSigned() << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << std::endl << "\033[1;31mTest Bureaucrat cannot sign default Form\033[0m" << std::endl;
		Bureaucrat H = Bureaucrat("Hugo", 150);
		std::cout << H << std::endl;
		Form F;
		try {H.signForm(F);}
		catch (const Form::GradeTooLowException &e)
		{
		std::cout << e.what() << std::endl;
		}
		std::cout << F.getIsSigned() << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << std::endl << "\033[1;31mTest Bureaucrat cannot sign custom Form\033[0m" << std::endl;
		Bureaucrat H = Bureaucrat("Hugo", 150);
		std::cout << H << std::endl;
		Form F = Form("License to chill", 20, 10);
		try {H.signForm(F);}
		catch (const Form::GradeTooLowException &e)
		{
		std::cout << e.what() << std::endl;
		}
		std::cout << F.getIsSigned() << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << std::endl << "\033[1;31mTest Bureaucrat can sign custom Form\033[0m" << std::endl;
		Bureaucrat H = Bureaucrat("Hugo", 15);
		std::cout << H << std::endl;
		Form F = Form("License to chill", 20, 10);
		try {H.signForm(F);}
		catch (const Form::GradeTooLowException &e)
		{
		std::cout << e.what() << std::endl;
		}
		std::cout << F.getIsSigned() << std::endl;
	}

	return (0);
}
