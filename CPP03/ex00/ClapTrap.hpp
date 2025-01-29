/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:08 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/29 13:48:15 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>


class ClapTrap {
	private:
	std::string _name ;
	uint	HP;
	uint	EP;
	uint	AD;
	
	public:
	void	attack(const std::string &target);
	void	takeDamage(uint amount);
	void	beRepaired(uint amount);
};
#endif
