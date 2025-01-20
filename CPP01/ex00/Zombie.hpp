/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:37:32 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/20 15:57:19 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef _ZOMBIE_HPP
# define _ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;
	public:
		void	announce(void);
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

};


class Contact
{
	private:
		std::string _index;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_phone_number(std::string str);
		void		set_nickname(std::string str);
		void		set_darkest_secret(std::string str);
		std::string	get_index();
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
};
#endif
