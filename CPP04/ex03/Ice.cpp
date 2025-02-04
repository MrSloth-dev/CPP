/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:16:16 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/04 11:33:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice"), type("ice") {
	std::cout << "Ice const" << std::endl;

}

Ice::~Ice() {
	std::cout << "Ice destr" << std::endl;
}

Ice::Ice(const Ice& other): AMateria("ice") {
	*this = other;
	this->_type = other._type;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		this->_type = other._type;
	}
}

Ice* Ice::clone() const {
	return new Ice();
}
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
