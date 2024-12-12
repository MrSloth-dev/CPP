/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:57:57 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/12 17:22:44 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "utils.hpp"
#include "contact.hpp"

#include <cstdlib>
#include <cctype>
#include <csignal>
#include <iostream>
#include <sstream>


class Phonebook
{
	private:
		Contact _contacts[8];
		int		_index;
	public:
		Phonebook(void);
		void	add(Contact contact);
		void	search(int index);
		void	print(Contact contact);
		Contact	get_contact(int index);
};
#endif //PHONEBOOK_HPP_
