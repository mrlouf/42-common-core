/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:17:40 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 16:27:31 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat(); 

	j->makeSound();
	i->makeSound();
	delete j;
	delete i;

	// AAnimal example;
	// Not allowed to create object of abstract class;

	}
	return 0;
}
