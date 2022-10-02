/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 18:24:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP_
#define PHONEBOOK_CLASS_HPP_

#include "Contact.class.hpp"

class PhoneBook
{
private:
    Contact contacts[8];

public:
    PhoneBook(void);
    ~PhoneBook(void);
    int add_contact(int contact_index);
    int search_contact(PhoneBook *phonebook);
};

#endif
