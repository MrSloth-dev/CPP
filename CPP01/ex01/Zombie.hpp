/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:37:32 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 12:35:53 by joao-pol         ###   ########.fr       */
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
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void setName(std::string name);

};

Zombie *zombieHorde(int N, std::string name);

#endif // _ZOMBIE_HPP
