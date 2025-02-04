/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:38 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 13:55:01 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog created" << std::endl;

}
Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog created with type: " << this->_type << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog died" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
}

void	Dog::setType(std::string type) {
	this->_type = type;
}

std::string	Dog::getType() const {
	return this->_type;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}
