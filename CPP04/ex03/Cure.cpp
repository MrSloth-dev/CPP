/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:16:16 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/04 11:33:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("ice"), type("ice") {
	std::cout << "Cure const" << std::endl;

}

Cure::~Cure() {
	std::cout << "Cure destr" << std::endl;
}

Cure::Cure(const Cure& other): AMateria("cure") {
	*this = other;
	this->_type = other._type;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		this->_type = other._type;
	}
}

Cure* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
