/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:27 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 17:14:53 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
	std::string _name;
	Weapon *_weapon;
	public:
	void	attack();
	HumanB(std::string);
	void	setWeapon(Weapon& weapon);
	~HumanB();
};
