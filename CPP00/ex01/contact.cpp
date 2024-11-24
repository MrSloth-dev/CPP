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

std::string	Contact::get_first_name(std::string str)
{
	return(this->_first_name);
}

std::string	Contact::get_last_name(std::string str)
{
	return(this->_last_name);
}

std::string	Contact::get_phone_number(std::string str)
{
	return(this->_phone_number);
}
