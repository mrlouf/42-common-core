/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:17:40 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 16:28:41 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	}

	std::cout << std::endl;

	{

	std::cout << "\033[1;31mAnimal Test\033[0m" << std::endl;

		Animal A;
		A.makeSound();

		Dog B;
		B.makeSound();
		B.Animal::makeSound();

		Cat C;
		C.makeSound();
		C.Animal::makeSound();

		WrongCat W;
		W.makeSound();
	}
	{
		std::cout << std::endl;
		std::cout << "\033[1;31mWrongAnimal Test\033[0m" << std::endl;

		const WrongAnimal *j = new(std::nothrow) WrongCat();
		if (!j)
		{
			delete j;
			return (1);
		}
		j->makeSound();
		delete j; // incomplete destruction/undefined behaviour if lack of virtual destructor in WrongAnimal!
		const WrongCat *c = new(std::nothrow) WrongCat();
		if (!c)
		{
			delete c;
			return (1);
		}
		c->WrongCat::makeSound();
		delete c;
	}

	return (0);
}