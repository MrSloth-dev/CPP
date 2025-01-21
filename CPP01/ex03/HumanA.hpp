/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:27 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 17:27:27 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA {
	private:
	std::string _name;
	Weapon _weapon;
	public:
	void	attack();
	HumanA(std::string , Weapon weapon);
	~HumanA();
};
