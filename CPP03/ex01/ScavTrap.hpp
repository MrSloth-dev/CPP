/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:44:46 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/30 17:01:03 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_
#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	bool _gateMode;
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& other);
	void	attack(const std::string &target);
	void	guardGate(void);
};
#endif
