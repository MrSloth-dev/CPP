/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:35:11 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/04 11:38:43 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character: public ICharacter {
	private:
	protected:
	AMateria* _inventory[4];
	std::string _name;
	public:
	Character();
	Character(const Character& other);
	~Character();
	Character& operator=(const Character& other);
};
