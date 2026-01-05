/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:23:52 by jweber            #+#    #+#             */
/*   Updated: 2026/01/05 11:35:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	std::string	str;
	size_t		str_len;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int arg_i = 1; arg_i < argc; arg_i++)
	{
		str = argv[arg_i];
		str_len = str.size();
		for (size_t	char_i = 0; char_i < str_len; char_i++)
			str[char_i] = std::toupper(str[char_i]);
		std::cout << str;
	}
	std::cout << std::endl;
}
