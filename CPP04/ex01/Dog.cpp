/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:38 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 17:40:54 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new(Brain)) {
	std::cout << "Dog created" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(), brain(new Brain(*other.brain)) {
	*this = other;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog died" << std::endl;
}

void	Dog::setType(std::string type) {
	this->_type = type;
}

std::string	Dog::getType() const {
	return this->_type;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		_type = other._type;
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "🐕Woof woof!🐕" << std::endl;
}

std::string	Dog::getIdea(unsigned int index) const {
	if (index < 1 || index > 100) {
		std::cout << "Index must be between 1 an 100" << std::endl;
		return "";
	}
	else
		return this->brain->ideas[index - 1];
}

void	Dog::setIdea(unsigned int index, std::string idea) {
	if (index <= 100)
		this->brain->ideas[index - 1] = idea;
}
