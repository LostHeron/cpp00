/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:41:19 by jweber            #+#    #+#             */
/*   Updated: 2026/01/05 14:44:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void			set_first_name(std::string str);
		std::string		get_first_name(void);
		std::string&	get_first_name_ref(void);

		void			set_last_name(std::string str);
		std::string		get_last_name(void);
		std::string&	get_last_name_ref(void);

		void			set_nickname(std::string);
		std::string		get_nickname(void);
		std::string&	get_nickname_ref(void);

		void			set_phone_number(std::string);
		std::string		get_phone_number(void);
		std::string&	get_phone_number_ref(void);
		
		void			set_darkest_secret(std::string);
		std::string		get_darkest_secret(void);
		std::string&	get_darkest_secret_ref(void);
};

std::ostream& operator<<(std::ostream& os, Contact contact);

#endif
