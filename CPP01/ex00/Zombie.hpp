/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:37:32 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 12:02:59 by joao-pol         ###   ########.fr       */
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

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif // _ZOMBIE_HPP
