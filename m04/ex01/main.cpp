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
		cat1->setIdeas(i, "meeh!");
	Cat *cat2 = new Cat(*cat1);
	for (size_t i = 0; i < 100; i++)
		cat1->setIdeas(i, "bleh!");
	cat1->printIdeas();
	cat2->printIdeas();

	delete cat1;
	delete cat2;
	return 0;
}
