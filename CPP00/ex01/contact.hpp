/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:08:31 by joao-pol          #+#    #+#             */
/*   Updated: 2024/09/27 22:09:37 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
#define CONTACT_HPP_
# include <string>

class Contact
{
	private:
		std::string _index;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
	public:
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_phone_number(std::string str);
		std::string	get_first_name(std::string str);
		std::string	get_last_name(std::string str);
		std::string	get_phone_number(std::string str);
};
#endif
