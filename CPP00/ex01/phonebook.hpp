/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:57:57 by joao-pol          #+#    #+#             */
/*   Updated: 2024/09/24 00:09:27 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "contact.hpp"

class Phonebook
{
	private:
		Contact _contacts[8];
		int		_index;
	public:
		Phonebook(void);
		~Phonebook(void);
		void	add(Contact contact);
		void	search(Contact contact);
		void	print(Contact contact);
		Contact	get_contact(int index);
};
#endif //PHONEBOOK_HPP_
