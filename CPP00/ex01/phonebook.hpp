/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:57:57 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/03 09:59:58 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

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
