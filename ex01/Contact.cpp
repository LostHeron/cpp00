/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:56:44 by jweber            #+#    #+#             */
/*   Updated: 2026/01/05 13:56:59 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <ostream>
#include <string>

std::ostream&	modify_os(std::ostream& os, std::string str);

std::ostream& operator<<(std::ostream& os, Contact contact)
{
	std::string	str;

	str = contact.get_first_name();
	modify_os(os, str);
	str = contact.get_last_name();
	modify_os(os, str);
	str = contact.get_nickname();
	modify_os(os, str);
	return (os);
}

std::ostream&	modify_os(std::ostream& os, std::string str)
{
	if (str.size() > 10)
	{
		os << "";
		os.write(&str[0], 9);
		os << ".";
	}
	else
	{
		os.width(10);
		os << str;
	}
	os << "|";
	return (os);
}

void		Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string& Contact::get_first_name_ref(void)
{
	return (this->first_name);
}

void		Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string&	Contact::get_last_name_ref(void)
{
	return (this->last_name);
}

void		Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string&	Contact::get_nickname_ref(void)
{
	return (this->nickname);
}

void		Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

std::string	Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string&	Contact::get_phone_number_ref(void)
{
	return (this->phone_number);
}

void		Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}

std::string&	Contact::get_darkest_secret_ref(void)
{
	return (this->darkest_secret);
}
