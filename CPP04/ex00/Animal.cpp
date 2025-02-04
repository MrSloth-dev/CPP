/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:08:21 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 13:54:45 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
/* class Animal {
	private:
	protected:
	std::string _name;
	public:
	Animal();
	Animal(std::string _name);
	~Animal();
	Animal& operator=(const Animal& other);
}; */

Animal::Animal() : _type("No Species"){
	std::cout << "Animal created" << std::endl;

}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal created with type: " << this->_type << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal died" << std::endl;
}

void	Animal::setType(std::string type) {
	this->_type = type;
}

std::string	Animal::getType() const {
	return this->_type;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "No Species No sound!" << std::endl;
}
