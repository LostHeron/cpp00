/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:14 by jweber            #+#    #+#             */
/*   Updated: 2026/01/05 17:11:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <ostream>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	this->nb_contact = 0;
	this->last_contact_index = -1;
}

void	PhoneBook::add_contact(Contact contact)
{
	if (this->nb_contact < MAX_CONTACTS)
		this->nb_contact = this->nb_contact + 1;
	this->last_contact_index = (this->last_contact_index + 1) % MAX_CONTACTS;
	this->contacts_list[this->last_contact_index] = contact;
}

std::ostream& operator<<(std::ostream& os, PhoneBook phonebook)
{
	if (phonebook.size() <= 0)
	{
		os << "no contact list in current phonebook" << std::endl;
		os << "please ADD at least one contact to search in the list" << std::endl;
		return (os);
	}
	for (int i = 0; i < phonebook.size(); i++)
	{
		std::cout << std::setw(45) << std::setfill('-') << "\n";
		std::cout << std::setfill(' ');
		os.width(10);
		os << i + 1;
		os << "|";
		os << phonebook.get_contact_i(i);
		std::cout << std::endl;
	}
	std::cout << std::setw(45) << std::setfill('-') << "\n";
	std::cout << std::setfill(' ');
	return (os);
}

Contact&	PhoneBook::get_contact_i(int i)
{
	return (this->contacts_list[i]);
}

int	PhoneBook::size(void)
{
	return (this->nb_contact);
}
