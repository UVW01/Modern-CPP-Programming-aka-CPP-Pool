/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	Cat *cat1 = new Cat();
	for (size_t i = 0; i < 100; i++)
		cat1->setIdea(i, "meeeeeeeeeeeeeeeeh!");

	Cat *cat2 = new Cat(*cat1);
	for (size_t i = 0; i < 100; i++)
		cat1->setIdea(i, "blaaaaaaaaaaaaaaah!");

	Dog *dog1 = new Dog();
	for (size_t i = 0; i < 100; i++)
		dog1->setIdea(i, "skriiiiiiiiiiiiiit!");

	Dog *dog2 = new Dog(*dog1);
	for (size_t i = 0; i < 100; i++)
		dog1->setIdea(i, "vrooooooooooooooom!");

	cat1->printIdeas();
	cat2->printIdeas();
	dog1->printIdeas();
	dog2->printIdeas();

	Animal *animals[50];
	for (size_t i = 0; i < 25; i++)
		animals[i] = new Cat(*cat1);
	for (size_t i = 25; i < 50; i++)
		animals[i] = new Dog();

	delete cat1;
	delete cat2;
	for (size_t i = 0; i < 50; i++)
		delete animals[i];

	return 0;
}
