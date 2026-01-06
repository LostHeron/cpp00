/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:06:52 by jweber            #+#    #+#             */
/*   Updated: 2026/01/05 17:14:44 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <ostream>
#include <sstream>

int		cmd_add(PhoneBook& phonebook);
int		cmd_search(PhoneBook& phonebook);
void	cmd_exit(int& stop);

int	main(void)
{
	std::string	input;
	int			stop;
	int			ret;
	PhoneBook	phonebook;

	stop = FALSE;
	while (stop == FALSE)
	{
		std::cout << std::endl << "What do you want to do ? (ADD, SEARCH, EXIT)" << std::endl;
		if (std::getline(std::cin, input).eof())
		{
			std::cout << MSG_ERROR_INPUT << std::endl;
			stop = TRUE;
			continue;
		}
		if (input == "ADD")
		{
			ret = cmd_add(phonebook);
			if (ret != SUCCESS)
			{
				if (ret == FAILURE_EXIT)
				{
					std::cout << MSG_ERROR_INPUT << std::endl;
					stop = TRUE;
				}
			}
		}
		else if (input == "SEARCH")
		{
			ret = cmd_search(phonebook);
			if (ret != SUCCESS)
			{
				if (ret == FAILURE_EXIT)
				{
					std::cout << MSG_ERROR_INPUT << std::endl;
					stop = TRUE;
				}
			}
		}
		else if (input == "EXIT")
			cmd_exit(stop);
		else
			std::cout << "\nerror: unkonwn command '" << input << "', choose between 'ADD', 'SEARCH', 'EXIT'" << std::endl;
	}
	return (0);
}

int	get_input(const std::string msg, std::string& str);

int	cmd_add(PhoneBook& phonebook)
{
	Contact			new_contact;
	std::string		input;
	int				ret;
	
	ret = get_input("Enter contact first name: ", new_contact.get_first_name_ref());
	if (ret != SUCCESS)
		return (ret);

	ret = get_input("Enter contact last name: ", new_contact.get_last_name_ref());
	if (ret != SUCCESS)
		return (ret);

	ret = get_input( "Enter contact nickname: ", new_contact.get_nickname_ref());
	if (ret != SUCCESS)
		return (ret);

	ret = get_input( "Enter contact phone number: ", new_contact.get_phone_number_ref());
	if (ret != SUCCESS)
		return (ret);

	ret = get_input("Enter contact darkest secret: ", new_contact.get_darkest_secret_ref());
	if (ret != SUCCESS)
		return (ret);

	phonebook.add_contact(new_contact);
	return (SUCCESS);
}

int	get_input(const std::string msg, std::string& str)
{
	std::string			tmp_str;
	std::string			remaining;
	std::stringstream	ss;

	std::cout << msg;
	std::getline(std::cin, tmp_str);
	if (std::cin.fail() || std::cin.eof())
	{
		return (FAILURE_EXIT);
	}
	ss << tmp_str;
	ss >> str;
	if (str == "")
	{
		std::cout << std::endl << "error: field must contain something ! " << std::endl;
		return (FAILURE);
	}
	ss >> remaining;
	if (remaining != "")
	{
		std::cout << std::endl << "error: please enter only one word per field!" << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}

int		check_entered_id(int& id, std::string& str);
void	print_contact(Contact& contact);

int	cmd_search(PhoneBook& phonebook)
{
	std::string			str;
	int					id;

	std::cout << phonebook;
	std::cout << "Select a contact to see more detail (enter a number): ";
	if (std::getline(std::cin, str).eof())
		return (FAILURE_EXIT);
	if (check_entered_id(id, str) != SUCCESS)
	{
		std::cout << std::endl << "error: could not convert '" << str << "' to integer" << std::endl;
		return (FAILURE);
	}
	if (1 <= id && id <= phonebook.size())
	{
		print_contact(phonebook.contacts_list[id - 1]);
	}
	else
	{
		std::cout << std::endl << "error: " << id << " is not a valid id" << std::endl;
	}
	return (SUCCESS);
}

int	check_entered_id(int& id, std::string& str)
{
	std::stringstream	ss;
	std::string			remaining;

	ss << str;
	ss >> id;
	if (ss.fail())
		return (FAILURE);
	ss >> remaining;
	if (remaining != "")
		return (FAILURE);
	return (SUCCESS);
}

void	print_contact(Contact& contact)
{
	std::cout << "first name: " << contact.get_first_name() << std::endl
		<< "last name: " << contact.get_last_name() << std::endl
		<< "nickname: " << contact.get_nickname() << std::endl
		<< "phone number: " << contact.get_phone_number() << std::endl
		<< "darkest secret: " << contact.get_darkest_secret() << std::endl
		<< std::endl;
}

void	cmd_exit(int& stop)
{
	stop = TRUE;
}
