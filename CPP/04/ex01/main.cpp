/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:17:40 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:49 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

/*
In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
Don’t forget to check for memory leaks.
A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
are deep copies!
*/

int main()
{
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat(); 

	delete j;//should not create a leak
	delete i;
	}
	{
	std::cout << std::endl;
	std::cout << "\033[1;31mShallow copy Test\033[0m" << std::endl;

	Dog basic;
		{
		Dog copy = basic;
		}
		basic.makeSound();
	}
	{
	std::cout << std::endl;
	std::cout << "\033[1;31mBrain & ideas Test w/cat\033[0m" << std::endl;

	Cat *C = new Cat();

	std::cout << "C Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;

	C->getBrain()->setIdea("Meow", 7);
	std::cout << "Original Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;

	Cat *Copy = new Cat(*C);

	delete C;

	std::cout << "Copy Idea 8 = \"" << Copy->getBrain()->getIdea(7) << "\"" << std::endl;
	Copy->getBrain()->setIdea("MeowMeowww", 7);
	std::cout << "Copy Idea 8 changed" << std::endl;
	std::cout << "Copy Idea 8 = \"" << Copy->getBrain()->getIdea(7) << "\"" << std::endl;

	delete Copy;
	}

	{
	std::cout << std::endl;
	std::cout << "\033[1;31mBrain & ideas Test w/dog\033[0m" << std::endl;

	Dog *C = new Dog();

	std::cout << "C Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;

	C->getBrain()->setIdea("Meow", 7);
	std::cout << "Original Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;

	Dog Copy = *C;

	std::cout << "Copy Idea 8 = \"" << Copy.getBrain()->getIdea(7) << "\"" << std::endl;
	Copy.getBrain()->setIdea("MeowMeowww", 7);
	std::cout << "Copy Idea 8 changed" << std::endl;
	std::cout << "Copy Idea 8 = \"" << Copy.getBrain()->getIdea(7) << "\"" << std::endl;

	std::cout << "Original Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;
	delete C;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[1;31mMixed array Test\033[0m" << std::endl;

		const Animal *array[20];

		for (int i = 0; i < 10; i++) {
			array[i] = new Cat();
		}
		for (int i = 10; i < 20; i++) {
			array[i] = new Dog();
		}

		for (int i = 0; i < 20; i++) {
			array[i]->makeSound();
		}

		for (int i = 0; i < 20; i++) {
			delete array[i];
		}
		
	}
	return 0;
}
