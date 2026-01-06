/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:40:04 by jweber            #+#    #+#             */
/*   Updated: 2026/01/05 17:11:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SUCCESS 0
# define FAILURE 1
# define FAILURE_EXIT 2

# define TRUE 1
# define FALSE 0

# define MSG_ERROR_INPUT "\nerror: a problem occured while retreiving user input"

# include "Contact.hpp"
# define MAX_CONTACTS 8

class PhoneBook
{
	public:
		Contact contacts_list[MAX_CONTACTS];
	private:
		int		last_contact_index;
		int		nb_contact;

	public:
		void	add_contact(Contact contact);
		int		size(void);
		PhoneBook();
};

std::ostream& operator<<(std::ostream& os, PhoneBook phonebook);

#endif
