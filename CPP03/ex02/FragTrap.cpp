/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:42:45 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/30 17:14:17 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("DEFAULT") {
	_HP = 100;
	_EP = 100;
	_AD = 30;
	std::cout << "Fragtrap: Hi! My name is DEFAULT! You want me? To join you? " 
		<< "I am SO excited. We will be best friends." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_HP = 100;
	_EP = 100;
	_AD = 30;
	std::cout << "Fragtrap: Hi! My name is "<< name << "! You want me? To join you? " 
		<< "I am SO excited. We will be best friends." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: I'm too pretty to die!" << std::endl;
}

void FragTrap::hightFivesGuys(void) {
	std::cout << "Secret handshake!" << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}
	return (*this);
}
