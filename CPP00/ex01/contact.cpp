/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:59:39 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/03 10:07:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_phone_number(std::string str)
{
	this->_phone_number = str;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->_darkest_secret = str;
}

std::string	Contact::get_index()
{
	return(this->_index);
}

std::string	Contact::get_first_name()
{
	return(this->_first_name);
}

std::string	Contact::get_last_name()
{
	return(this->_last_name);
}

std::string	Contact::get_nickname()
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number()
{
	return(this->_phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return(this->_darkest_secret);
}
