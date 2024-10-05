/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:39:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/05 21:56:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		int index;
		Contact contacts[8];

		std::string validateInput(const std::string& input);

	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void displayContactEntries();
		void displayContact(const Contact& contact);
		void exit();
};

#endif
