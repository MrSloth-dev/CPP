/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:42:45 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/30 17:12:05 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("DEFAULT"), _HP(10), _EP(10), _AD(0) {
	std::cout << "I am a CL4P-TP steward bot, but my friends call me " << _name
	<< " the Claptrap! Or they would, if any of them were still alive!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AD(0) {
	std::cout << "I am a CL4P-TP steward bot, but my friends call me " << _name
	<< " the Claptrap! Or they would, if any of them were still alive!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "I will die the way i live, annoying!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "PROTECT ME, SQUIRE!!" << std::endl;
	if (amount >= this->_HP) {
		this->_HP = 0;
		std::cout << "RIP" << std::endl;
	}
	else
		this->_HP -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_EP == 0 || this->_HP == 0) {
		std::cout << "Stairs? I can't climb up stairs!! " << std::endl;
	}
	else {
		this->_EP--;
		this->_HP +=amount;
		std::cout << this->_name << " was repaired "
			<< ", healing " << amount << " points of health!" << std::endl;
	}
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_EP == 0 || this->_HP == 0) {
		std::cout << "Stairs? I can't climb down stairs!! " << std::endl;
	}
	else {
		this->_EP--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_AD << " points of damage!" << std::endl;
	}
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}
	return (*this);
}
