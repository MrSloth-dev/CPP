/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:59:46 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/03 10:40:08 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

Phonebook::Phonebook()
{
	this->_index = 0;
}
void Phonebook::add(Contact contact)
{
	this->_contacts[_index] = contact;
	this->_index = (this->_index + 1) % 8;
}

std::string Format(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	std::ostringstream formatted;
	formatted << std::right << std::setw(10) << str;
	return (formatted.str());
}

void Phonebook::search(std::string str)
{
	int found = 0;
	for (int i = 0; i < 8; i++)
	{
		if (str.compare(this->_contacts[i].get_first_name()) == 0
			||str.compare(this->_contacts[i].get_last_name()) == 0
			||str.compare(this->_contacts[i].get_phone_number()) == 0)
		{
			std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| " << std::endl;
			// std::cout << "|                                                      |" << std::endl;
			std::cout << "|"<<Format(this->_contacts[i].get_first_name());
			std::cout << "|"<<Format(this->_contacts[i].get_last_name());
			std::cout << "|"<<Format(this->_contacts[i].get_nickname());
			std::cout << "|"<<Format(this->_contacts[i].get_phone_number());
			std::cout << "|"<<Format(this->_contacts[i].get_darkest_secret())<< "|" << std::endl;
			std::cout << "|______________________________________________________| " << std::endl;
			found++;
		}
	}
	if (!found)
		std::cout << "No contacts found!" << std::endl;
}

Contact Phonebook::get_contact(int index)
{
	return (this->_contacts[index]);
}

std::string FormatColumn(std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	std::ostringstream formatted;
	formatted << std::right << std::setw(10) << str;
	return (formatted.str());
}
