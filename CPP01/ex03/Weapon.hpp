/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:41:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 17:25:20 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {
private:
	std::string _type;
public:
	const std::string getType() const;
	void	setType(std::string);
	Weapon();
	Weapon(std::string);
	~Weapon();
	Weapon& operator=(const Weapon &other);
};
