/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:38 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 13:55:48 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat created" << std::endl;

}
Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat created with type: " << this->_type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat died" << std::endl;
}

void	Cat::setType(std::string type) {
	this->_type = type;
}

std::string	Cat::getType() const {
	return this->_type;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}
