/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:42:45 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/30 17:14:17 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_HP = 100;
	_EP = 50;
	_AD = 20;
	std::cout << "Scavtrap: You want me? To join you? " 
		<< "I am SO excited. We will be best friends." << std::endl;
}

ScavTrap::~ScavTrap() {};

void	ScavTrap::attack(const std::string& target) {
	if (this->_EP == 0 || this->_HP == 0) {
		std::cout << "ScavTrap:  I'm out of oil!" << std::endl;
	}
	else {
		this->_EP--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_AD << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) {
	this->_gateMode = true;
	std::cout << "ScavTrap: Recompiling my combat code!" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}
	return (*this);
}
