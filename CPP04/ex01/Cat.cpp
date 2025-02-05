/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:38 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 16:36:18 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new(Brain)) {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(), brain(new Brain(*other.brain)) {
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat died" << std::endl;
}

void	Cat::setType(std::string type) {
	this->_type = type;
}

std::string	Cat::getType() const {
	return this->_type;
}

void	Cat::makeSound() const {
	std::cout << "🐈Meow Meow!🐈" << std::endl;
}

std::string	Cat::getIdea(unsigned int index) {
	if (index < 1 || index < 100) {
		std::cout << "Index must be between 1 an 100" << std::endl;
		return "";
	}
	else
		return this->brain->ideas[index - 1];
}

void	Cat::setIdea(unsigned int index, std::string idea) {
	if (index < 1 || index < 100) {
		std::cout << "Index must be between 1 an 100" << std::endl;
	}
	else
		this->brain->ideas[index - 1] = idea;
}
