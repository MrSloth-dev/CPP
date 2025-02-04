/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:08:21 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 13:58:03 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"
/* class WrongAnimal {
	private:
	protected:
	std::string _name;
	public:
	WrongAnimal();
	WrongAnimal(std::string _name);
	~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& other);
}; */

WrongAnimal::WrongAnimal() : _type("No Species"){
	std::cout << "WrongAnimal created" << std::endl;

}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal created with type: " << this->_type << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal died" << std::endl;
}

void	WrongAnimal::setType(std::string type) {
	this->_type = type;
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "No Species No sound!" << std::endl;
}
