/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:42:44 by mnaimi            #+#    #+#             */
/*   Updated: 2022/07/31 15:17:52 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP_
# define CONTACT_CLASS_HPP_

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact(void);
		~Contact(void);
		std::string get_member(int index);
		void 		set_member(std::string str, int index);
		void 		clear_member(int index);
};

#endif
