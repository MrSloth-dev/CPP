/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:38 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 14:02:33 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat created" << std::endl;

}
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat created with type: " << this->_type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat died" << std::endl;
}

void	WrongCat::setType(std::string type) {
	this->_type = type;
}

std::string	WrongCat::getType() const {
	return this->_type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Cat goes Bark Bark?" << std::endl;
}
