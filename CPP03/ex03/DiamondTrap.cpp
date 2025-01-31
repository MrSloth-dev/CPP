/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:42:45 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/31 13:29:40 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
	ScavTrap::_EP = ScavTrap::_EP;
	_EP = 100;
	_AD = 30;
	std::cout << "Diamondtrap: Hi! My name is "<< name << "! You want me? To join you? " 
		<< "I am SO excited. We will be best friends." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: I'm too pretty to die!" << std::endl;
}

void DiamondTrap::hightFivesGuys(void) {
	std::cout << "Secret handshake!" << std::endl;
};

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}
	return (*this);
}
