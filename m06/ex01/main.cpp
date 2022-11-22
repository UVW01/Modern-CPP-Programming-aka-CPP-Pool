/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:42:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/22 22:42:32 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serial.hpp"

/* ************************************************************************** */
/* ********************************  MAIN  ********************************** */
/* ************************************************************************** */

int main(void)
{
	Data data;

	std::cout << "Original data address: " << &data << std::endl;
	std::cout << "Serialize data address: " << serialize(&data) << std::endl;
	uintptr_t p = serialize(&data);
	std::cout << "Deserialize data address: " << deserialize(p) << std::endl;
	std::cout << "Deserialize(Serialize) data address: " << \
		deserialize(serialize(&data)) << std::endl;
	return 0;
}
